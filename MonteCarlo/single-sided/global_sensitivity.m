% ----------------------------------------------------------------------- % 
%
%   Monte-Carlo simulation code for integral model 
%   written in OpenModelica
%
%   Yunjae Hwang (yunjaeh@stanford.edu)
%   
% ----------------------------------------------------------------------- %
clear; clc;

delete(gcp('nocreate'));
tic
mkdir ./data
mkdir ./data/input
% mkdir ./data/output
mkdir ./input
mkdir ./output

num_core    = 12;       % # of cores used for parallel process
num_param   = 9;        % # of uncertain parameters
num_iter    = 30;       % # of total number of iteration
num_sample  = 100;      % # of samples in each iteration

% Procedures:
%   - define the range of uncertain parameters
%   1. input and output directories
%   2. 


% nominal parameteres       : np(1, ..., n)
%   values not changing in the simulation
num_case = '19';
% date = 'Night_0206';    config ='night_WV';
% date = 'Night_0205';    config ='night_SV';
% date = 'Night_0211';    config ='night_SW';
date = 'Night_0210';    config ='night_SFV';


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
up( 2,1) = 1;         up( 2,2) = 4;     % Heat convective coefficient; external
% up( 3,1) = 52.7;        up( 3,2) = 75.9;    % Conductivity; roof
% up( 4,1) = 0.6;         up( 4,2) = 1.31;    % Conductivity; wall

% up( 6,1) = 0.8;         up( 6,2) = 0.9;    % Emissivity; wall
up( 3,1) = 0.29;        up( 3,2) = 0.66;    % Absorptivity; roof
up( 4,1) = 0.06;         up( 4,2) = 0.346;    % Emissivity; roof
up( 5,1) = 1-0.3;         up( 5,2) = 1+0.3;    % Ventilation rate 1
up( 6,1) = 1-0.3;         up( 6,2) = 1+0.3;    % Ventilation rate 2

% infiltration range
% avg of min, mean, max: 3.9487, 4.3925, 4.8275
% min(min), max(max): 3.27, 5.94
% up( 7,1) = 3.27;        up( 7,2) = 5.94;    % Infiltration
up( 7,1) = 0.0+eps;        up( 7,2) = 1.0-eps;    % Temperature quantile
up( 8,1) = 0.0+eps;        up( 8,2) = 1.0-eps;    % Radiation quantile
up( 9,1) = 0.0+eps;        up( 9,2) = 1.0-eps;    % Wind quantile



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
%         system(['echo ''',num2str(A(i,10)),''' >> ./input/UQ_input_',num2str(i),'.in']);
%         system(['echo ''',num2str(A(i,11)),''' >> ./input/UQ_input_',num2str(i),'.in']);
%         system(['echo ''',num2str(A(i,12)),''' >> ./input/UQ_input_',num2str(i),'.in']);
%         system(['echo ''',num2str(A(i,13)),''' >> ./input/UQ_input_',num2str(i),'.in']);
%         system(['echo ''',num2str(A(i,14)),''' >> ./input/UQ_input_',num2str(i),'.in']);
        
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
system('rmdir input output');

delete(gcp('nocreate'));
toc






