%% pre-process
% read output files and filter
clear;  clc;
cd('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/Night_SV');
mkdir ./output
% num_param   = 9;        % # of uncertain parameters
num_iter    = 50;       % # of total number of iteration
num_sample  = 100;      % # of samples in each iteration

data_input=[];
len_time = 3377;

data.temp_out = zeros(num_sample*num_iter, len_time);
data.rad = zeros(num_sample*num_iter, len_time);
data.wind = zeros(num_sample*num_iter, len_time);
data.temp_in = zeros(num_sample*num_iter, len_time);
data.vent_rate = zeros(num_sample*num_iter, len_time);
data.wall = zeros(num_sample*num_iter, len_time);
data.wall_in = zeros(num_sample*num_iter, len_time);
data.wall_out = zeros(num_sample*num_iter, len_time);

data.roof = zeros(num_sample*num_iter, len_time);
data.roof_in = zeros(num_sample*num_iter, len_time);
data.roof_out = zeros(num_sample*num_iter, len_time);


for iter = 1:num_iter
    
    data_temp = csvread(['./input/input_',num2str(iter),'.csv']);
    data_input = [data_input; data_temp];
    
    for i =1:num_sample
        fname = ['./output_',num2str(iter),'/result_',num2str(i)];
        system(['./OutputFiltering ',fname,'.csv ', fname,'.out']);

        idx = num_sample * (iter-1) + i
%         f_out_raw = ['./output_',num2str(iter),'/result_',num2str(i),'.csv'];

         
        data_temp = dlmread([fname,'.out'],' ',1,0);    %csvread([dir,'output_',num2str(iter),'/result_',num2str(i),'.csv'],1);
%       
        data.temp_out(idx,:) = data_temp(:,1)';
        data.rad(idx,:) = data_temp(:,2)';
        data.wind(idx,:) = data_temp(:,3)';
        data.temp_in(idx,:) = data_temp(:,4)';
        data.wall(idx,:) = data_temp(:,5)';
        data.wall_in(idx,:) = data_temp(:,6)';
        data.wall_out(idx,:) = data_temp(:,7)';
        data.roof(idx,:) = data_temp(:,8)';
        data.roof_in(idx,:) = data_temp(:,9)';
        data.roof_out(idx,:) = data_temp(:,10)';
        data.vent_rate(idx,: ) = data_temp(:,11)';

% %         try
% %         catch
% %             display(['error in reading input, iteration: ', num2str(iter),', sample: ',num2str(i)]);
% %             temp_in(idx,:) = NaN;
% %             vent_rate(idx,:) = NaN;
% %             wall_inner_a(idx,:) = NaN;
% %             wall_inner_b(idx,:) = NaN;
% %             wall_outer_a(idx,:) = NaN;
% %             wall_outer_b(idx,:) = NaN;
% %             continue
% %         end
% %         
    end
end

data.input = data_input;
save('data_summary.mat','data');
% figure();
% for i=1:14
%     subplot(3,5,i);
%     histogram(data_input(:,i),20);
% end



%% plot input and outputs
load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/integral_time_stamp.mat');     % load time stamp


vol_house = 17.72;
ach_in = 4.75;
ach = data.vent_rate*3600/vol_house;

for i=1:size(data.vent_rate,1)
    ach(i,:) = ach(i,:) + ach_in*data.input(i,11);
end



figure();
subplot(3,2,1); hold on
patch([t_stamp' fliplr(t_stamp')], [max(data.temp_out) fliplr(min(data.temp_out))]-273.15,[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.8);
patch([t_stamp' fliplr(t_stamp')], [max(data.temp_in) fliplr(min(data.temp_in))]-273.15,[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.8);
plot(t_stamp, mean(data.temp_out)-273.15,'k','linewidth',1.5);
plot(t_stamp, mean(data.temp_in)-273.15,'b','linewidth',1.5);
xlim([0 24]);
ylabel('Temperature [^\circC]');

subplot(3,2,2); hold on
patch([t_stamp' fliplr(t_stamp')], [max(ach) fliplr(min(ach))],[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.8);
plot(t_stamp, mean(ach),'k','linewidth',1.5);
xlim([0 24]);
ylim([0 20]);
ylabel('ACH [1/h]');



subplot(3,2,3); hold on
patch([t_stamp' fliplr(t_stamp')], [max(data.wall_out) fliplr(min(data.wall_out))]-273.15,[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.8);
patch([t_stamp' fliplr(t_stamp')], [max(data.wall_in) fliplr(min(data.wall_in))]-273.15,[1.0 0.8 0.8],...
    'edgecolor','none','facealpha',0.8);
plot(t_stamp, mean(data.wall_out)-273.15,'b','linewidth',1.5);
plot(t_stamp, mean(data.wall_in)-273.15,'r','linewidth',1.5);
xlim([0 24]);
ylabel('Temperature [^\circC]');

subplot(3,2,4); hold on
patch([t_stamp' fliplr(t_stamp')], [max(data.roof_out) fliplr(min(data.roof_out))]-273.15,[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.9);
patch([t_stamp' fliplr(t_stamp')], [max(data.roof_in) fliplr(min(data.roof_in))]-273.15,[1.0 0.8 0.8],...
    'edgecolor','none','facealpha',0.9);
plot(t_stamp, mean(data.roof_out)-273.15,'b','linewidth',1.5);
plot(t_stamp, mean(data.roof_in)-273.15,'r','linewidth',1.5);
xlim([0 24]);
ylabel('Temperature [^\circC]');





subplot(3,2,5); hold on
patch([t_stamp' fliplr(t_stamp')], [max(data.rad) fliplr(min(data.rad))],[0.8 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(data.rad),'k','linewidth',1.5);
xlim([0 24]);
ylabel('Solar radiation [W]');

subplot(3,2,6); hold on
patch([t_stamp' fliplr(t_stamp')], [max(data.wind) fliplr(min(data.wind))],[0.8 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(data.wind),'k','linewidth',1.5);
xlim([0 24]);
ylabel('Wind speed [m/s]');







%%

% plot
% clear;  clc;
% close all;

load('/home/yunjaeh/OpenFOAM/yunjaeh-4.0/run/UQ/uq_2019/integral_time_stamp.mat');     % load time stamp
load('/home/yunjaeh/matlab/BD_field_measurement/Jan2019/measurement_data.mat'); % load measurement data
t_stamp = t_stamp+12;


% % night, WV, 0206
%       12.67, 23:54 - 00:30
%       15.95, 00:35 - 01:11
% load('./night_WV/data_summary.mat');  
% title_config = 'Night_WV';
% date_exp = '20190206120000';
% ach_test = [23+54/60, 24+30/60, 12.67;...
%     24+35/60, 25+11/60, 15.95];


% % night, SV, 0205
%       12.34, 02:06 - 02:45
%       13.98, 03:42 - 04:17
load('./night_SV/data_summary.mat');
title_config = 'Night_SV';
date_exp = '20190205120000';
ach_test = [26+6/60, 26+45/60, 12.34;...
    27+42/60, 28+17/60, 13.98];



% night, SW, 0211
%       20.35, 00:11 - 00:42
%       21.83, 03:16 - 03:42
% %       23.38, 03:46 - 04:10
% load('./night_SW/data_summary.mat');
% title_config = 'Night_SW';
% date_exp = '20190211120000';
% ach_test = [24+11/60, 24+42/60, 20.35;...
%     27+16/60, 27+42/60, 21.83;...
%     27+46/60, 28+10/60, 23.38];


% night, SFV, 0209
%       22.61, 22:10 - 22:45
%       15.66, 22:50 - 23:22
%       15.77, 23:30 - 23:59
% load('./night_SFV/data_summary.mat');
% title_config = 'Night_SFV';
% date_exp = '20190210120000';
% ach_test = [22+10/60, 22+45/60, 22.61;...
%     22+50/60, 23+22/60, 15.66;...
%     23+30/60, 23+59/60, 15.77];


% night, W only, 0206
%       15.17, 01:15 - 01:51
%       14.40, 02:23 - 03:00
%       16.37, 03:03 - 03:39
% load('./night_W_only/data_summary.mat');
% title_config = 'Night_W_only';
% date_exp = '20190206120000';
% ach_test = [25+15/60, 25+51/60, 15.17;...
%     26+23/60, 27+00/60, 14.40;...
%     27+ 3/60, 27+39/60, 16.37];

% night, S only, 0210
%       15.42, 01:10 - 01:46
%       13.89, 02:08 - 02:44
%       17.95, 02:57 - 03:30
% load('./night_S_only/data_summary.mat');
% title_config = 'Night; S only';
% date_exp = '20190210120000';
% ach_test = [25+10/60, 25+46/60, 15.42;...
%     26+08/60, 26+44/60, 13.89;...
%     26+57/60, 27+30/60, 17.95];


% night, V only, 0205
%        7.71, 04:21 - 04:56
%        8.92, 05:22 - 05:58
% load('./night_V_only/data_summary.mat');
% title_config = 'Night_V_only';
% date_exp = '20190205120000';
% ach_test = [26+21/60, 26+56/60, 7.71;...
%     27+22/60, 27+58/60, 8.92];


%

vol_house = 17.72;
ach_in = 4.75;
ach = data.vent_rate*3600/vol_house;
% ach_old = data_old.vent_rate*3600/vol_house;

for i=1:size(data.vent_rate,1)
    ach(i,:) = ach(i,:) + ach_in*data.input(i,11);
%     ach_old(i,:) = ach_old(i,:) + ach_in*data_old.input(i,7);
end


%%
figure();
hold on
patch([t_stamp', fliplr(t_stamp')],...
    [min(ach),fliplr(max(ach))],...
    [0 0 0]+0.7,'edgecolor','none');
%     [mean(ach)-2*std(ach),fliplr(mean(ach)+2*std(ach))],...
    
% patch([t_stamp', fliplr(t_stamp')],...
%     [min(ach_old),fliplr(max(ach_old))],...
%     [0.3 0 0]+0.7,'edgecolor','none');
%     [mean(ach_old)-2*std(ach_old),fliplr(mean(ach_old)+2*std(ach_old))],...
    

plot(t_stamp, mean(ach,'omitnan'),'k','linewidth',2);
% plot(t_stamp, mean(ach_old,'omitnan'),'r','linewidth',2);
for i=1:size(ach_test,1)
%     idx_temp  = ach_test(i,1) < t_stamp & t_stamp <= ach_test(i,2);
    plot([ach_test(i,1), ach_test(i,2)], [ach_test(i,3), ach_test(i,3)], 'r','linewidth',2);
end


alpha(0.7);

grid on
xlabel('Time [hr]');
ylabel('ACH [1/hr]');
xlim([12 36]);
xticks(12:12:36);
ylim([10 20]);
xticklabels({'Noon','Midnight','Noon'});
% ylim([0 20]);
% title(title_config);
% legend('New','Old');
print([title_config,'_ACH'],'-dpng');


% Plotting summary in all configurations
% ach_summary = [];
% for i=1:size(ach_test,1)
%     idx_temp  = ach_test(i,1) < t_stamp & t_stamp <= ach_test(i,2);
%     
%     plot([ach_test(i,1), ach_test(i,2)], [ach_test(i,3), ach_test(i,3)], 'b','linewidth',2);
%     ach_summary(i,1) = ach_test(i,3);
%     ach_summary(i,2) = mean(mean(ach(:,idx_temp)));
%     ach_summary(i,3) = mean(std(ach(:,idx_temp)));
% end
% ach_summary_SFV = ach_summary;
% save('ACH_summary.mat','ach_summary_SFV','-append');

%%
ach_summary = [ach_summary_WV;ach_summary_SV;ach_summary_SW;ach_summary_SFV];%;...
%     ach_summary_W;ach_summary_S;ach_summary_V];

figure();
hold on
errorbar(ach_summary(:,1),ach_summary(:,2),2*ach_summary(:,3),'bo');
axis([0 30 0 30]);
plot(0:30, 0:30, 'k:');
xlabel('ACH [1/hr]: measurement ');
ylabel('ACH [1/hr]: prediction ');
xticks([0 10 20 30]);   xticklabels({'0','10','20','30'});
yticks([0 10 20 30]);   yticklabels({'0','10','20','30'});
legend('Single-sided ventilation model');
legend('boxoff')

% figure(); hold on
% scatter(ach_summary(:,1),ach_summary(:,2)-4.75);
% 
% P = polyfit(ach_summary(:,1),ach_summary(:,2)-4.75,1);
% x_fit = 0:25;
% y_fit = P(1)*x_fit+P(2);
% plot(x_fit, y_fit, 'k:');
% grid on
% axis([0 25 -10 25]);
% xlabel('ACH measurement [1/hr]');
% ylabel('ACH prediction [1/hr]');

% legend('Data', ['Linear fit: ',num2str(P(1)),'x',num2str(P(2))]);

%% Temperature comparison
for i=12:35
    idx_temp = i<=t_stamp & t_stamp <(i+1);
    T.temp_in(:,i-11) = mean(data.temp_in(:,idx_temp),2) -273.15;
    T.wall(:,i-11) = mean(data.wall(:,idx_temp),2) - 273.15;
    T.wall_in(:,i-11) = mean(data.wall_in(:,idx_temp),2) - 273.15;
    T.wall_out(:,i-11) = mean(data.wall_out(:,idx_temp),2) - 273.15;
    T.roof(:,i-11) = mean(data.roof(:,idx_temp),2) - 273.15;
    T.roof_in(:,i-11) = mean(data.roof_in(:,idx_temp),2) - 273.15;
    T.roof_out(:,i-11) = mean(data.roof_out(:,idx_temp),2) - 273.15;
end

for i=12:35
    idx_temp = i<=t_stamp & t_stamp <(i+1);
    T_old.temp_in(:,i-11) = mean(data_old.temp_in(:,idx_temp),2) -273.15;
    T_old.wall(:,i-11) = mean(data_old.wall(:,idx_temp),2) - 273.15;
    T_old.wall_in(:,i-11) = mean(data_old.wall_in(:,idx_temp),2) - 273.15;
    T_old.wall_out(:,i-11) = mean(data_old.wall_out(:,idx_temp),2) - 273.15;
    T_old.roof(:,i-11) = mean(data_old.roof(:,idx_temp),2) - 273.15;
    T_old.roof_in(:,i-11) = mean(data_old.roof_in(:,idx_temp),2) - 273.15;
    T_old.roof_out(:,i-11) = mean(data_old.roof_out(:,idx_temp),2) - 273.15;
end

%
clear idx

date_target = datetime(date_exp,'InputFormat','yyyyMMddHHmmss');
idx.OUT = (date_target-day(1)) <= hourly.OUT.time &  hourly.OUT.time <= date_target;
idx.CT = (date_target-day(1)) <= hourly.CT.time &  hourly.CT.time <= date_target;
idx.NW = (date_target-day(1)) <= hourly.NW.time &  hourly.NW.time <= date_target;
idx.SW = (date_target-day(1)) <= hourly.SW.time &  hourly.SW.time <= date_target;
idx.NE = (date_target-day(1)) <= hourly.NE.time &  hourly.NE.time <= date_target;
idx.SE = (date_target-day(1)) <= hourly.SE.time &  hourly.SE.time <= date_target;

idx.W_wall = (date_target-day(1)) <= hourly.W_wall.time &  hourly.W_wall.time <= date_target;
idx.E_wall = (date_target-day(1)) <= hourly.E_wall.time &  hourly.E_wall.time <= date_target;
idx.N_wall = (date_target-day(1)) <= hourly.N_wall.time &  hourly.N_wall.time <= date_target;
idx.S_wall = (date_target-day(1)) <= hourly.S_wall.time &  hourly.S_wall.time <= date_target;
idx.Roof   = (date_target-day(1)) <= hourly.Roof.time &  hourly.Roof.time <= date_target;

figure();
hold on

% patch([12:35', fliplr(12:35')], [mean(T_old.temp_in)-2*std(T_old.temp_in),...
%     fliplr(mean(T_old.temp_in)+2*std(T_old.temp_in))], [0.3 0 0]+0.7,'edgecolor','none');
% plot(12:35, mean(T_old.temp_in),'r.-','linewidth',2);


plot(12:36, hourly.CT.low.mean(idx.CT),'Color',[0 0 0.6]+0.4);%'b-');
plot(12:36, hourly.NW.low.mean(idx.NW),'Color',[0 0 0.6]+0.4);%'b-');
plot(12:36, hourly.SW.low.mean(idx.SW),'Color',[0 0 0.6]+0.4);%'b-');
plot(12:36, hourly.NE.low.mean(idx.NE),'Color',[0 0 0.6]+0.4);%'b-');
plot(12:36, hourly.SE.low.mean(idx.SE),'Color',[0 0 0.6]+0.4);%'b-');

plot(12:36, hourly.CT.mid.mean(idx.CT),'Color',[0 0.6 0]+0.4);%'k-');
plot(12:36, hourly.NW.mid.mean(idx.NW),'Color',[0 0.6 0]+0.4);%'k-');
plot(12:36, hourly.SW.mid.mean(idx.SW),'Color',[0 0.6 0]+0.4);%'k-');
plot(12:36, hourly.NE.mid.mean(idx.NE),'Color',[0 0.6 0]+0.4);%'k-');
plot(12:36, hourly.SE.mid.mean(idx.SE),'Color',[0 0.6 0]+0.4);%'k-');

plot(12:36, hourly.CT.top.mean(idx.CT),'Color',[0.6 0 0]+0.4);%'r-');
plot(12:36, hourly.NW.top.mean(idx.NW),'Color',[0.6 0 0]+0.4);%'r-');
plot(12:36, hourly.SW.top.mean(idx.SW),'Color',[0.6 0 0]+0.4);%'r-');
plot(12:36, hourly.NE.top.mean(idx.NE),'Color',[0.6 0 0]+0.4);%'r-');
plot(12:36, hourly.SE.top.mean(idx.SE),'Color',[0.6 0 0]+0.4);%'r-');

% plot(12:36, hourly.OUT.mean(idx.OUT),'k:','linewidth',2);

patch([12:35', fliplr(12:35')], [mean(T.temp_in)-2*std(T.temp_in),...
    fliplr(mean(T.temp_in)+2*std(T.temp_in))], [0.6 0.6 0.6],'edgecolor','none');
plot(12:35, mean(T.temp_in),'k','linewidth',3);


title('Indoor temperature');
% xlim([12 36]);  xticks(12:12:36);   xticklabels({'Noon','Midnight','Noon'});
xlim([12 35]);  xticks(12:11.5:35);   xticklabels({'Noon','Midnight','Noon'});
ylabel('Temperature [C]');
print([title_config,'_indoor'],'-dpng');

alpha(0.7)

%%

figure();
subplot(1,2,1); hold on
% patch([t_stamp', fliplr(t_stamp')], ...
patch([12:35', fliplr(12:35')], ...
    [mean(T.wall_in)-2*std(T.wall_in), fliplr(mean(T.wall_in)+2*std(T.wall_in))],...
    [0 0 0]+0.7,'edgecolor','none');
% plot(t_stamp, mean(T.wall_in),'k','linewidth',2);
plot(12:35, mean(T.wall_in),'k.-','linewidth',2);
plot(12:36, hourly.W_wall.in.mean(idx.W_wall),'r.-');
plot(12:36, hourly.E_wall.in.mean(idx.E_wall),'g.-');
plot(12:36, hourly.N_wall.in.mean(idx.N_wall),'b.-');
plot(12:36, hourly.S_wall.in.mean(idx.S_wall),'m.-');
plot(12:36, hourly.OUT.mean(idx.OUT),'k:','linewidth',3);
title('Wall inner surface temp.');
xlim([12 36]);  xticks(12:12:36);   xticklabels({'Noon','Midnight','Noon'});
ylim([12 32]);

subplot(1,2,2); hold on
% patch([t_stamp', fliplr(t_stamp')], ...
patch([12:35', fliplr(12:35')], ...
    [mean(T.wall_out)-2*std(T.wall_out), fliplr(mean(T.wall_out)+2*std(T.wall_out))],...
    [0 0 0]+0.7,'edgecolor','none');
% plot(t_stamp, mean(T.wall_out),'k','linewidth',2);
plot(12:35, mean(T.wall_out),'k.-','linewidth',2);
plot(12:36, hourly.N_wall.out.mean(idx.N_wall),'b.-');
plot(12:36, hourly.S_wall.out.mean(idx.S_wall),'m.-');
plot(12:36, hourly.OUT.mean(idx.OUT),'k:','linewidth',3);
title('Wall outer surface temp.');
xlim([12 36]);  xticks(12:12:36);   xticklabels({'Noon','Midnight','Noon'});
ylim([12 32]);
% print([title_config,'_wall_surface'],'-dpng');


% roof temperature comparison 
figure();
subplot(1,2,1); hold on
% patch([t_stamp', fliplr(t_stamp')], ...
patch([12:35', fliplr(12:35')], ...
    [mean(T.roof_in)-2*std(T.roof_in), fliplr(mean(T.roof_in)+2*std(T.roof_in))],...
    [0 0 0]+0.7,'edgecolor','none');
% plot(t_stamp, mean(T.roof_in),'k','linewidth',2);
plot(12:35, mean(T.roof_in),'k.-','linewidth',2);
plot(12:36, hourly.Roof.in.mean(idx.Roof),'r.-');
plot(12:36, hourly.OUT.mean(idx.OUT),'k:','linewidth',3);
title('Roof inner surface temp.');
xlim([12 36]);  xticks(12:12:36);   xticklabels({'Noon','Midnight','Noon'});
ylim([15 45]);

subplot(1,2,2); hold on
% patch([t_stamp', fliplr(t_stamp')], ...
patch([12:35', fliplr(12:35')], ...
    [mean(T.roof_in)-2*std(T.roof_out), fliplr(mean(T.roof_out)+2*std(T.roof_in))],...
    [0 0 0]+0.7,'edgecolor','none');
% plot(t_stamp, mean(T.roof_out),'k','linewidth',2);
plot(12:35, mean(T.roof_out),'k.-','linewidth',2);
plot(12:36, hourly.Roof.out.mean(idx.Roof),'r.-');
plot(12:36, hourly.OUT.mean(idx.OUT),'k:','linewidth',3);

title('Roof outer surface temp.');
xlim([12 36]);  xticks(12:12:36);   xticklabels({'Noon','Midnight','Noon'});
ylim([15 45]);
% print([title_config,'_roof_surface'],'-dpng');


%% Sobol indices
% uncertain parameters
up( 1,1) = 1;        up( 1,2) = 4;     % Heat convective coefficient; internal
up( 2,1) = 1;        up( 2,2) = 10;     % Heat convective coefficient; external
up( 3,1) = 0.6;      up( 3,2) = 1.31;    % Conductivity; roof
up( 4,1) = 52.7;      up( 4,2) = 75.9;    % Conductivity; wall
up( 5,1) = 0.1;      up( 5,2) = 0.2;    % Emissivity; roof
up( 6,1) = 0.8;      up( 6,2) = 0.9;    % Emissivity; wall
% up( 7,1) = 0.2;      up( 7,2) = 0.5;    % C_D; opening 1
% up( 8,1) = 0.4;      up( 8,2) = 0.8;    % C_D; opening 2
up( 7,1) = 0.8;      up( 7,2) = 1.2;    % Infiltration

num_param   = 7;        % # of uncertain parameters
qoi = data.temp_in;
var_total =  var(qoi);
sobol_indices = zeros(num_param,3377);

for p =1:num_param
    dim_space = 80;
    x_space = linspace(up(p,1), up(p,2), dim_space+1);
%     idx_space = zeros(dim_space,size(input_data,2));
    var_save = zeros(3377,dim_space);
    for i=1:dim_space
        idx_space = (x_space(i) <= data.input(:,p)) & (x_space(i+1) > data.input(:,p)); 
        var_save(:,i) =  mean(qoi(idx_space,:))';
    end
    sobol_indices(p,:) = var(var_save')./var_total;
end

mean(sum(sobol_indices))


figure();
hold on
for p=1:num_param
   plot(t_stamp, sobol_indices(p,:),'linewidth',2);
end
legend('h_{in}', 'h_{out}', 'k_{roof}', 'k_{wall}', ...
    '\epsilon_{roof}','\epsilon_{wall}', 'Infiltration',...
    'location','eastoutside');
xlim([12 36]);
ylabel('Sobol index');
xlabel('Time [hr]');    xticks(12:12:36);   xticklabels({'Noon','Midnight','Noon'});
title('Sobol indices');




%% convergence of statistics (mean and std)
convergence_mean = zeros(5000,24);
convergence_std = zeros(5000,24);
for i=1:5000
    convergence_mean(i,:) = mean(hourly_avg_temp_in(1:i,:),'omitnan');
    convergence_std(i,:) = mean(hourly_std_temp_in(1:i,:),'omitnan');
end


figure();
hold on
pt_stt = 10;

% for i=1:24
%     subplot(1,2,1); hold on
%     plot(pt_stt:5000, convergence_mean(pt_stt:end,i),'b');
%     subplot(1,2,2); hold on
%     plot(pt_stt:5000, convergence_std(pt_stt:end,i),'b');
% end
subplot(1,2,1);
plot(pt_stt:5000, convergence_mean(pt_stt:end,12),'b');
xlabel('# sample');
ylabel('Mean temperature');
axis([0 5000 31 32.5]);

subplot(1,2,2);
plot(pt_stt:5000, convergence_std(pt_stt:end,12),'b');
xlabel('# sample');
ylabel('Standard deviation');
axis([0 5000 0.3 0.4]);

% plot(1:24, mean(temp_in_hourly,'omitnan')+2*std(temp_in_hourly,'omitnan'),'b');
% plot(1:24, mean(temp_in_hourly,'omitnan'),'k','linewidth',2);
% plot(1:24, mean(temp_in_hourly,'omitnan')-2*std(temp_in_hourly,'omitnan'),'b');



%% input uncertain parameters distribution
up( 1,1) = 1;        up( 1,2) = 4;     % Heat convective coefficient; internal
up( 2,1) = 1;        up( 2,2) = 10;     % Heat convective coefficient; external
up( 3,1) = 0.6;      up( 3,2) = 1.31;    % Conductivity; roof
up( 4,1) = 52.7;      up( 4,2) = 75.9;    % Conductivity; wall
up( 5,1) = 0.1;      up( 5,2) = 0.2;    % Emissivity; roof
up( 6,1) = 0.8;      up( 6,2) = 0.9;    % Emissivity; wall
% up( 7,1) = 0.2;      up( 7,2) = 0.5;    % C_D; opening 1
% up( 8,1) = 0.4;      up( 8,2) = 0.8;    % C_D; opening 2
up( 7,1) = 0.8;      up( 7,2) = 1.2;    % Infiltration


figure();
for i=1:7
    subplot(3,3,i);
    histogram(data.input(:,i),linspace(up(i,1),up(i,2),20),'normalization','pdf');
    title(['Uncertain parameter: ',num2str(i)]);
end



