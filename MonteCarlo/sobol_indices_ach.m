clear;  clc;
%%% ACH comparison
% load('/home/yunjaeh/github/Bangladesh_measurement/ACH/ach_post_process.mat');
% night_ACH= ACH_mean_rms;

% Window / Vent	
%   0205, 23:54 – 00:30 
%   0206, 00:35 – 01:11
% Skylight / Vent	
%   0205, 02:06 – 02:45 
%   0205, 03:42 – 04:17
% Skylight / Window
%   0211, 00:11 – 00:42 
%   0211, 03:16 – 03:42 
%   0211, 03:46 – 04:10
% Skylight / Floor vent
%   0209, 22:10 – 22:45 
%   0209, 22:50 – 23:22 
%   0209, 23:30 – 23:59 
%   0211, 01:06 – 01:43


% load prediction data
night_timing = [22+10/60,   22+45/60;...    % SFV 1
    22+50/60,   23+22/60;...    % SFV 2
    23+30/60,   23+59/60;...    % SFV 3
    26+6/60,    26+45/60;...    % SV 1
    27+42/60,   28+17/60;...    % SV 2
    23+54/60,   24+30/60;...    % WV 1
    24+35/60,   25+11/60;...    % WV 2
    24+11/60,   24+42/60;...    % SW 1
    27+16/60,   27+42/60;...    % SW 2
    27+46/60,   28+10/60];      % SW 3
    

load('./single-sided/data_v5/wv/data_summary.mat');     night_wv_single = data;
load('./single-sided/data_v5/sv/data_summary.mat');     night_sv_single = data;
load('./single-sided/data_v5/sw/data_summary.mat');     night_sw_single = data;
load('./single-sided/data_v5/sfv/data_summary.mat');    night_sfv_single = data;

load('./cross/data_v4/wv/data_summary.mat');     night_wv_cross = data;
load('./cross/data_v4/sv/data_summary.mat');     night_sv_cross = data;
load('./cross/data_v4/sw/data_summary.mat');     night_sw_cross = data;
load('./cross/data_v4/sfv/data_summary.mat');    night_sfv_cross = data;

% Window / Vent	
%   0205, 23:54 – 00:30 
%   0206, 00:35 – 01:11
% Skylight / Vent	
%   0205, 02:06 – 02:45 
%   0205, 03:42 – 04:17
% Skylight / Window
%   0211, 00:11 – 00:42 
%   0211, 03:16 – 03:42 
%   0211, 03:46 – 04:10
% Skylight / Floor vent
%   0209, 22:10 – 22:45 
%   0209, 22:50 – 23:22 
%   0209, 23:30 – 23:59 
%   0211, 01:06 – 01:43


% load prediction data
day_timing = [15+11/60,   15+50/60;...    % SFV 1
    16+19/60,   16+54/60;...    % SFV 2
    15+3/60,    15+39/60;...    % SV 1
    15+55/60,    16+20/60;...    % SV 2
    16+26/60,   17+1/60;...    % SV 3
    15+4/60,    15+40/60;...    % WV 1
    15+56/60,   16+30/60;...    % WV 2
    14+51/60,   15+27/60;...    % SW 1
    15+29/60,   16+4/60];    % SW 2
day_timing = day_timing+3;

load('./single-sided/data_v6.vent/wv/data_summary.mat');     day_wv_single = data;
load('./single-sided/data_v6.vent/sv/data_summary.mat');     day_sv_single = data;
load('./single-sided/data_v6.vent/sw/data_summary.mat');     day_sw_single = data;
load('./single-sided/data_v6.vent/sfv/data_summary.mat');    day_sfv_single = data;

load('./cross/data_v6.vent/day_wv/data_summary.mat');     day_wv_cross = data;
load('./cross/data_v6.vent/day_sv/data_summary.mat');     day_sv_cross = data;
load('./cross/data_v6.vent/day_sw/data_summary.mat');     day_sw_cross = data;
load('./cross/data_v6.vent/day_sfv/data_summary.mat');    day_sfv_cross = data;

%% initial process and save data
vol_house = 17.72;

load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/time_stamp3.mat');     % load time stamp
night_sfv_single.ach = night_sfv_single.vent_rate*3600/vol_house;
night_sv_single.ach = night_sv_single.vent_rate*3600/vol_house;
night_wv_single.ach = night_wv_single.vent_rate*3600/vol_house;
night_sw_single.ach = night_sw_single.vent_rate*3600/vol_house;

night_sfv_cross.ach = night_sfv_cross.vent_rate*3600/vol_house;
night_sv_cross.ach = night_sv_cross.vent_rate*3600/vol_house;
night_wv_cross.ach = night_wv_cross.vent_rate*3600/vol_house;
night_sw_cross.ach = night_sw_cross.vent_rate*3600/vol_house;

ACH_single = {night_sfv_single, night_sfv_single, night_sfv_single, ...
    night_sv_single, night_sv_single, ...
    night_wv_single, night_wv_single,...
    night_sw_single, night_sw_single, night_sw_single};
   
ACH_cross = {night_sfv_cross, night_sfv_cross, night_sfv_cross, ...
    night_sv_cross, night_sv_cross, ...
    night_wv_cross, night_wv_cross, ...
    night_sw_cross, night_sw_cross, night_sw_cross};

for i=1:size(ACH_single,2)
    idx = night_timing(i,1) < t_stamp & t_stamp < night_timing(i,2);
    night_single.ACH{i} = ACH_single{i}.ach(:,idx)';
    night_single.input{i} = ACH_single{i}.input;
    night_cross.ACH{i} = ACH_cross{i}.ach(:,idx)';
    night_cross.input{i} = ACH_cross{i}.input;
end


load('/home/yunjaeh/github/UQ/MonteCarlo/cross/time_stamp4.mat');
day_sfv_single.ach = day_sfv_single.vent_rate*3600/vol_house;
day_sv_single.ach = day_sv_single.vent_rate*3600/vol_house;
day_wv_single.ach = day_wv_single.vent_rate*3600/vol_house;
day_sw_single.ach = day_sw_single.vent_rate*3600/vol_house;

day_sfv_cross.ach = day_sfv_cross.vent_rate*3600/vol_house;
day_sv_cross.ach = day_sv_cross.vent_rate*3600/vol_house;
day_wv_cross.ach = day_wv_cross.vent_rate*3600/vol_house;
day_sw_cross.ach = day_sw_cross.vent_rate*3600/vol_house;


ACH_single = {day_sfv_single, day_sfv_single,...
    day_sv_single, day_sv_single, day_sv_single,...
    day_wv_single, day_wv_single, ...
    day_sw_single, day_sw_single};
ACH_cross = {day_sfv_cross, day_sfv_cross,...
    day_sv_cross, day_sv_cross, day_sv_cross, ...
    day_wv_cross, day_wv_cross, ...
    day_sw_cross, day_sw_cross };

for i=1:9
    idx = day_timing(i,1) < t_stamp & t_stamp < day_timing(i,2);
    day_single.ACH{i} = ACH_single{i}.ach(:,idx)';
    day_single.input{i} = ACH_single{i}.input;
    day_cross.ACH{i} = ACH_cross{i}.ach(:,idx)';
    day_cross.input{i} = ACH_cross{i}.input;
end
    
save('Data_ACH_sobol.mat','day_single','day_cross','night_single','night_cross');


%%

% single-sided
numParam = 9;
up = zeros(numParam, 2);
up( 1,1) = 1;           up( 1,2) = 4;     % Heat convective coefficient; internal
up( 2,1) = 1;           up( 2,2) = 4;     % Heat convective coefficient; external
up( 3,1) = 0.29;        up( 3,2) = 0.66;    % Reflectance; roof
up( 4,1) = 0.06;         up( 4,2) = 0.346;    % Emissivity roof
up( 5,1) = 1-0.29;         up( 5,2) = 1+0.29;    % Ventilation rate 1
up( 6,1) = 1-0.29;         up( 6,2) = 1+0.29;    % Ventilation rate 2
up( 7,1) = 0.0+eps;        up( 7,2) = 1.0-eps;    % Temperature quantile
up( 8,1) = 0.0+eps;        up( 8,2) = 1.0-eps;    % Radiation quantile
up( 9,1) = 0.0+eps;        up( 9,2) = 1.0-eps;    % Wind quantile

% day 
temp_data = day_single;    num_test = 9;
SI_day = zeros(num_test, numParam);
for j=1:num_test
    qoi = mean(temp_data.ACH{j});
    var_total =  var(qoi);
    for p = 1:numParam
        % divide the range of uncertain paramter into N windows
        dimSpace = 80;
        xSpace = linspace(up(p,1), up(p,2), dimSpace+1);
    %     idx_space = zeros(dim_space,size(input_data,2));
        var_save = zeros(1,dimSpace);
        for i=1:dimSpace
            idx_space = (xSpace(i) <= temp_data.input{j}(:,p)) & (xSpace(i+1) > temp_data.input{j}(:,p)); 
            var_save(:,i) =  mean(qoi(idx_space))';
        end
        SI_day(j,p) = var(var_save')./var_total;
    end
end
temp_data = night_single;    num_test = 10;
SI_night = zeros(num_test, numParam);
for j=1:num_test
    qoi = mean(temp_data.ACH{j});
    var_total =  var(qoi);
    for p = 1:numParam
        % divide the range of uncertain paramter into N windows
        dimSpace = 80;
        xSpace = linspace(up(p,1), up(p,2), dimSpace+1);
    %     idx_space = zeros(dim_space,size(input_data,2));
        var_save = zeros(1,dimSpace);
        for i=1:dimSpace
            idx_space = (xSpace(i) <= temp_data.input{j}(:,p)) & (xSpace(i+1) > temp_data.input{j}(:,p)); 
            var_save(:,i) =  mean(qoi(idx_space))';
        end
        SI_night(j,p) = var(var_save')./var_total;
    end
end


figure();
hold on
boxplot([SI_day; SI_night])

ylim([0 1]);
xlim([0 numParam+1]);

xlabel('Uncertain parameters');
ylabel('Sobol index');
yticks(0:0.5:1);


%
subplot(4,1,1);  hold on
for j=1:2
    plot(1:numParam, SI_day(j,:) ,'bo');
end
for j=1:3
    plot(1:numParam, SI_night(j,:) ,'bo');
end

subplot(4,1,2); hold on
for j=3:5
    plot(1:numParam, SI_day(j,:) ,'bo');
end
for j=4:5
    plot(1:numParam, SI_night(j,:) ,'bo');
end

subplot(4,1,3); hold on
for j=6:7
    plot(1:numParam, SI_day(j,:) ,'bo');
end
for j=6:7
    plot(1:numParam, SI_night(j,:) ,'bo');
end

subplot(4,1,4); hold on
for j=8:9
    plot(1:numParam, SI_day(j,:) ,'bo');
end
for j=8:10
    plot(1:numParam, SI_night(j,:) ,'bo');
end

for i=1:4
    subplot(4,1,i)
    ylim([0 1]);
    ylabel('Sobol index');
    xlim([0 numParam+1]);
    xticks(1:numParam);
    xticklabels({'h_{in}','h_{out}','\rho_{roof}', '\epsilon_{roof}',...
    'C_1','C_2','p_{temp}','p_{rad}','p_{wind}'});
end



%%
% cross
numParam = 8;        % # of uncertain parameters
up = zeros(numParam, 2);
up( 1,1) = 1;           up( 1,2) = 4;     % Heat convective coefficient; internal
up( 2,1) = 0.75;           up( 2,2) = 1.25;     % Heat convective coefficient; external
up( 3,1) = 0.29;        up( 3,2) = 0.66;    % Reflectance; roof
up( 4,1) = 0.06;         up( 4,2) = 0.346;    % Emissivity roof
up( 5,1) = 0.35;         up( 5,2) = 0.65;    % Ventilation rate 1
up( 6,1) = 0.0+eps;        up( 6,2) = 1.0-eps;    % Temperature quantile
up( 7,1) = 0.0+eps;        up( 7,2) = 1.0-eps;    % Radiation quantile
up( 8,1) = 0.0+eps;        up( 8,2) = 1.0-eps;    % Wind quantile



% day 
temp_data = day_cross;    num_test = 9;
SI_day = zeros(num_test, numParam);
for j=1:num_test
    qoi = mean(temp_data.ACH{j});
    var_total =  var(qoi);
%     var_total

    for p = 1:numParam
        % divide the range of uncertain paramter into N windows
        dimSpace = 80;
        xSpace = linspace(up(p,1), up(p,2), dimSpace+1);
        if(p==5)
            xSpace(1:dimSpace/2) = linspace(-up(p,2), -up(p,1), dimSpace/2);
            xSpace(dimSpace/2+1 : dimSpace+1) = linspace(up(p,1), up(p,2), dimSpace/2+1);
        end
        var_save = zeros(1,dimSpace);
        for i=1:dimSpace
            idx_space = (xSpace(i) <= temp_data.input{j}(:,p)) & (xSpace(i+1) > temp_data.input{j}(:,p)); 
%             sum(idx_space)
            var_save(:,i) =  mean(qoi(idx_space))';
        end
        SI_day(j,p) = var(var_save','omitnan')./var_total;
    end
end

temp_data = night_cross;    num_test = 10;
SI_night = zeros(num_test, numParam);
for j=1:num_test
    qoi = mean(temp_data.ACH{j});
    var_total =  var(qoi);
%     var_total

    for p = 1:numParam
        % divide the range of uncertain paramter into N windows
        dimSpace = 80;
        xSpace = linspace(up(p,1), up(p,2), dimSpace+1);
        if(p==5)
            xSpace(1:dimSpace/2) = linspace(-up(p,2), -up(p,1), dimSpace/2);
            xSpace(dimSpace/2+1 : dimSpace+1) = linspace(up(p,1), up(p,2), dimSpace/2+1);
        end
        var_save = zeros(1,dimSpace);
        for i=1:dimSpace
            idx_space = (xSpace(i) <= temp_data.input{j}(:,p)) & (xSpace(i+1) > temp_data.input{j}(:,p)); 
%             sum(idx_space)
            var_save(:,i) =  mean(qoi(idx_space))';
        end
        SI_night(j,p) = var(var_save','omitnan')./var_total;
    end
end

%
% day_timing = [15+11/60,   15+50/60;...    % SFV 1
%     16+19/60,   16+54/60;...    % SFV 2
%     15+3/60,    15+39/60;...    % SV 1
%     15+55/60,    16+20/60;...    % SV 2
%     16+26/60,   17+1/60;...    % SV 3
%     15+4/60,    15+40/60;...    % WV 1
%     15+56/60,   16+30/60;...    % WV 2
%     14+51/60,   15+27/60;...    % SW 1
%     15+29/60,   16+4/60];    % SW 2
% night_timing = [22+10/60,   22+45/60;...    % SFV 1
%     22+50/60,   23+22/60;...    % SFV 2
%     23+30/60,   23+59/60;...    % SFV 3
%     26+6/60,    26+45/60;...    % SV 1
%     27+42/60,   28+17/60;...    % SV 2
%     23+54/60,   24+30/60;...    % WV 1
%     24+35/60,   25+11/60;...    % WV 2
%     24+11/60,   24+42/60;...    % SW 1
%     27+16/60,   27+42/60;...    % SW 2
%     27+46/60,   28+10/60];      % SW 3

figure();
boxplot([SI_day; SI_night])

ylim([0 1]);
xlim([0 numParam+1]);

xlabel('Uncertain parameters');
ylabel('Sobol index');
yticks(0:0.5:1);

% xticks(1:numParam);
% xticklabels({'h_{in}','h_{out}','\rho_{roof}', '\epsilon_{roof}',...
%     '\DeltaC_p','p_{temp}','p_{rad}','p_{wind}'});


figure();
subplot(4,1,1);  hold on
for j=1:2
    plot(1:numParam, SI_day(j,:) ,'ro');
end
for j=1:3
    plot(1:numParam, SI_night(j,:) ,'ro');
end

subplot(4,1,2); hold on
for j=3:5
    plot(1:numParam, SI_day(j,:) ,'ro');
end
for j=4:5
    plot(1:numParam, SI_night(j,:) ,'ro');
end

subplot(4,1,3); hold on
for j=6:7
    plot(1:numParam, SI_day(j,:) ,'ro');
end
for j=6:7
    plot(1:numParam, SI_night(j,:) ,'ro');
end

subplot(4,1,4); hold on
for j=8:9
    plot(1:numParam, SI_day(j,:) ,'ro');
end
for j=8:10
    plot(1:numParam, SI_night(j,:) ,'ro');
end

for i=1:4
    subplot(4,1,i)
    ylim([0 1]);
    ylabel('Sobol index');
    xlim([0 numParam+1]);
    xticks(1:numParam);
    xticklabels({'h_{in}','h_{out}','\rho_{roof}', '\epsilon_{roof}',...
        '\DeltaC_p','p_{temp}','p_{rad}','p_{wind}'});
end




%%
figure();

subplot(2,1,1);
plot(1:numParam, SI_day ,'ro');
subplot(2,1,2);
plot(1:numParam, SI_night ,'bo');

















