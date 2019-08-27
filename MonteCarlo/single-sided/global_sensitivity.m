% ----------------------------------------------------------------------- % 
%
%   Monte-Carlo simulation code for integral model 
%   written in OpenModelica
%
%   Yunjae Hwang (yunjaeh@stanford.edu)
%   
% ----------------------------------------------------------------------- %
delete(gcp('nocreate'));
tic
mkdir ./data
mkdir ./data/input
% mkdir ./data/output
mkdir ./input
mkdir ./output

num_core    = 12;       % # of cores used for parallel process
num_param   = 11;        % # of uncertain parameters
num_iter    = 50;       % # of total number of iteration
num_sample  = 100;      % # of samples in each iteration

% Procedures:
%   - define the range of uncertain parameters
%   1. input and output directories
%   2. 


% nominal parameteres       : np(1, ..., n)
%   values not changing in the simulation
num_case = '19';
date = 'night_0210';
config ='night_SFV';


% height_1 = '0.91';      area_1 = '0.62';        % window
height_1 = '0.25';      area_1 = '0.6598';      % skylight
% height_1 = '0.43';    area_1 = '0.05';          % rear vent

% height_2 = '0.43';    area_2 = '0.05';          % rear vent
% height_2 = '0.91';    area_2 = '0.62';          % window
height_2 = '0.09';    area_2 = '0.005';         % floor vent

% height_2 = '0.0';       area_2 ='0.0';          % single sided




message = ['case, ', num_case, ...
    ', date, ', date, ...
    ', configuration, ', config, ...
    ', height_1, ', height_1, ...
    ', height_2, ', height_2, ...
    ', area_1, ', area_1, ...
    ', area_2, ', area_2,  ...
    ];
system(['echo ',message,' >> ./case.csv']);



% uncertain parameters      : up(num_param, 2)
%   first column  : minimum of UP range
%   second column : maximum of UP range
up = zeros(num_param, 2);
up( 1,1) = 1;           up( 1,2) = 4;     % Heat convective coefficient; internal
up( 2,1) = 0.8;         up( 2,2) = 1.2;     % Heat convective coefficient; external
up( 3,1) = 52.7;        up( 3,2) = 75.9;    % Conductivity; roof
up( 4,1) = 0.6;         up( 4,2) = 1.31;    % Conductivity; wall
up( 5,1) = 0.1;         up( 5,2) = 0.2;    % Emissivity; roof
up( 6,1) = 0.8;         up( 6,2) = 0.9;    % Emissivity; wall
up( 7,1) = 0.29;        up( 7,2) = 0.66;    % Absorptivity; wall
up( 8,1) = 0.8;         up( 8,2) = 1.2;    % Coefficient 1
up( 9,1) = 0.8;         up( 9,2) = 1.2;    % Coefficient 2
up( 10,1) = 0.8;        up( 10,2) = 1.2;    % Coefficient 3
up( 11,1) = 0.8;        up( 11,2) = 1.2;    % Infiltration



for iter = 1:num_iter
    A = rand(num_sample,num_param);
    for i=1:num_param
        A(:,i) = up(i,1) + (up(i,2) - up(i,1))*A(:,i);
    end
    csvwrite(['./data/input/input_',num2str(iter),'.csv'],A,0,0);
    
%     parfor i=1:num_sample
    for i=1:num_sample
        system(['echo ',date,' > ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ',height_1,' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ',height_2,' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ',area_1,' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ',area_2,' >> ./input/UQ_input_',num2str(i),'.in']);
        
        
        system(['echo ''',num2str(A(i,1)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,2)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,3)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,4)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,5)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,6)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,7)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,8)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,9)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,10)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        system(['echo ''',num2str(A(i,11)),''' >> ./input/UQ_input_',num2str(i),'.in']);
    end
    
    % Run OpenModelica script
    parfor i=1:num_sample
        system(['mkdir ./workdir.',num2str(i)]);                            % create temporary workspace
        system(['cp ./template/* ./workdir.',num2str(i),'/']);              % copy open modelica files
        
        system(['cp ./input/UQ_input_',num2str(i),'.in ',...
            './workdir.',num2str(i),'/UQ_input.in']);                       % copy input file to working diretory
        cd(['./workdir.',num2str(i)]);
        system(['./RunSimulation']);                                        % run simulation
% %         system(['awk -F, ''{print $2, $230, $130, $30, $33, $134, $124, $24, $27, $128}'' ./workspace/*.csv > ../output/result_',num2str(i),'.csv']);
% %         system(['awk ./workspace/*.csv ../output/result_',num2str(i),'.csv']);
        system(['cp ./workspace/OUTPUT_FILTERED.dat ../output/result_',num2str(i),'.csv']);
        cd('..');
        system(['rm -r ./workdir.',num2str(i)]);  
    end
    system('rm -r ./input/*')
    system(['mv ./output ./data/output_',num2str(iter)])
    system('mkdir ./output')
end  

delete(gcp('nocreate'));
toc






