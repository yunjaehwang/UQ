%% pre-process
% read output files and filter
clear;  clc;
cd('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/data/');
% cd('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/data_night/wv/');
% add temperature measurements and compare it to the prediction result
load('/home/yunjaeh/github/Bangladesh_measurement/TemperatureWind/Data/MeasurementDataTable.mat');

num_param   = 9;        % # of uncertain parameters
num_iter    = 30;       % # of total number of iteration
num_sample  = 100;      % # of samples in each iteration

data_input=[];
len_time = 5400;

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
        % system(['./OutputFiltering ',fname,'.csv ', fname,'.out']);

        idx = num_sample * (iter-1) + i
%         f_out_raw = ['./output_',num2str(iter),'/result_',num2str(i),'.csv'];

        
        data_temp = dlmread([fname,'.csv'],' ',1,0);    
        if(size(data_temp,1) ==len_time)
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
        else
            display('Skip');
        end
        

    end
end

data.input = data_input;
idx_diverged = find(data.wind(:,1) ==0);
if(~isempty(idx_diverged))
    fn = fieldnames(data);
    for i=1:numel(fn)
        for j=length(idx_diverged):-1:1
            data.(fn{i})(idx_diverged(j),:)=[];
%              data.input(idx_diverged(j),:)=[];
        end
    end
end


save('data_summary.mat','data');

figure();
for i=1:num_param
    subplot(3,5,i);
    histogram(data_input(:,i),20);
end


%% plot input and outputs
% load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/data_night/sfv/data_summary.mat');
load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/time_stamp3.mat');     % load time stamp

vol_house = 17.72;
% ach_in = 4.75;
ach = data.vent_rate*3600/vol_house;

% for i=1:size(data.vent_rate,1)
%     ach(i,:) = ach(i,:) + data.input(i,7);
% end

figure();

%%% inputs
% outdoor temperature
subplot(2,3,1); hold on
plot(t_stamp, mean(data.temp_out)-273.15,'k','linewidth',1.5);
% plot(t_stamp, mean(data.temp_in)-273.15,'b','linewidth',1.5);
patch([t_stamp' fliplr(t_stamp')], [max(data.temp_out) fliplr(min(data.temp_out))]-273.15,[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
% patch([t_stamp' fliplr(t_stamp')], [max(data.temp_in) fliplr(min(data.temp_in))]-273.15,[0.8 0.8 1.0],...
%     'edgecolor','none','facealpha',0.5);

legend('Outdoor temperature','Indoor temperature');
xlim([12 36]);      xlabel('Time');
ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});


% solar radiation
subplot(2,3,2); hold on
patch([t_stamp' fliplr(t_stamp')], [max(data.rad) fliplr(min(data.rad))],[0.8 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(data.rad),'k','linewidth',1.5);

xlim([12 36]);      xlabel('Time');
ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});

ylabel('Solar radiation [W]');

% wind speed
subplot(2,3,3); hold on
patch([t_stamp' fliplr(t_stamp')], [max(data.wind) fliplr(min(data.wind))],[0.8 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(data.wind),'k','linewidth',1.5);
plot(t_stamp, mean(data.wind)+std(data.wind),'k:','linewidth',1.5);
plot(t_stamp, mean(data.wind)-std(data.wind),'k:','linewidth',1.5);

xlim([12 36]);      xlabel('Time');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});
ylabel('Wind speed [m/s]');



%%% outputs
% wall surface temperature
subplot(2,3,4); hold on
plot(t_stamp, mean(data.wall_out)-273.15,'b','linewidth',1.5);
plot(t_stamp, mean(data.wall_in)-273.15,'r','linewidth',1.5);
patch([t_stamp' fliplr(t_stamp')], [max(data.wall_out) fliplr(min(data.wall_out))]-273.15,[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.5);
patch([t_stamp' fliplr(t_stamp')], [max(data.wall_in) fliplr(min(data.wall_in))]-273.15,[1.0 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);

xlim([12 36]);      xlabel('Time');
ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});


legend('Outer wall surface','Inner wall surface');

% roof surface temperature
subplot(2,3,5); hold on
plot(t_stamp, mean(data.roof_out)-273.15,'b','linewidth',1.5);
plot(t_stamp, mean(data.roof_in)-273.15,'r','linewidth',1.5);
patch([t_stamp' fliplr(t_stamp')], [max(data.roof_out) fliplr(min(data.roof_out))]-273.15,[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.5);
patch([t_stamp' fliplr(t_stamp')], [max(data.roof_in) fliplr(min(data.roof_in))]-273.15,[1.0 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);

xlim([12 36]);      xlabel('Time');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});
ylabel('Temperature [^\circC]');
legend('Outer roof surface','Inner roof surface');


% ach
subplot(2,3,6); hold on
patch([t_stamp' fliplr(t_stamp')], [max(ach) fliplr(min(ach))],[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.8);
plot(t_stamp, mean(ach)+std(ach),'k:','linewidth',1.5);
plot(t_stamp, mean(ach),'k','linewidth',1.5);
plot(t_stamp, mean(ach)-std(ach),'k:','linewidth',1.5);

xlim([12 36]);      xlabel('Time');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});
% ylim([0 20]);
ylabel('ACH [1/h]');



%%
%%% time average, span = 30 min

dt = 0.5;
t_averaged = 0:dt:(36-dt);
ci = 0.025;

for i= 1:length(t_averaged)
% for i = 1
    idx = t_averaged(i) < t_stamp & t_stamp < (t_averaged(i)+dt);
    
    [f,x] = ecdf(reshape(data.temp_in(:,idx)-273.15,1,[]));
    T_indoor.mean(i) = mean(reshape(data.temp_in(:,idx),1,[]))-273.15;
    T_indoor.ci_min(i) = max( x(f < ci) );
    T_indoor.ci_max(i) = min( x(f > (1-ci) ) );

    
    [f,x] = ecdf(reshape(data.wall_in(:,idx)-273.15,1,[]));
    T_wall_in.mean(i) = mean(reshape(data.wall_in(:,idx),1,[]))-273.15;
    T_wall_in.ci_min(i) = max( x(f < ci) );
    T_wall_in.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(data.wall_out(:,idx)-273.15,1,[]));
    T_wall_out.mean(i) = mean(reshape(data.wall_out(:,idx),1,[]))-273.15;
    T_wall_out.ci_min(i) = max( x(f < ci) );
    T_wall_out.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(data.roof_in(:,idx)-273.15,1,[]));
    T_roof_in.mean(i) = mean(reshape(data.roof_in(:,idx),1,[]))-273.15;
    T_roof_in.ci_min(i) = max( x(f < ci) );
    T_roof_in.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(data.roof_out(:,idx)-273.15,1,[]));
    T_roof_out.mean(i) = mean(reshape(data.roof_out(:,idx),1,[]))-273.15;
    T_roof_out.ci_min(i) = max( x(f < ci) );
    T_roof_out.ci_max(i) = min( x(f > (1-ci) ) );
end


%% indoor air temperature
targetDate = datetime(2019,2,6,12,0,0);
timeIdx = (targetDate-hours(36)) <= hourly.Time & hourly.Time <= targetDate ; 
 

figure();
subplot(1,2,1);
hold on
% measurement
plot(0:36, hourly.mean.CT_low(timeIdx), 'b'); 
plot(0:36, hourly.mean.NE_low(timeIdx), 'b'); 
plot(0:36, hourly.mean.NW_low(timeIdx), 'b'); 
plot(0:36, hourly.mean.SE_low(timeIdx), 'b'); 
plot(0:36, hourly.mean.SW_low(timeIdx), 'b'); 

plot(0:36, hourly.mean.CT_mid(timeIdx), 'k'); 
plot(0:36, hourly.mean.NE_mid(timeIdx), 'k'); 
plot(0:36, hourly.mean.NW_mid(timeIdx), 'k'); 
plot(0:36, hourly.mean.SE_mid(timeIdx), 'k'); 
plot(0:36, hourly.mean.SW_mid(timeIdx), 'k'); 

plot(0:36, hourly.mean.CT_top(timeIdx), 'r'); 
plot(0:36, hourly.mean.NE_top(timeIdx), 'r'); 
plot(0:36, hourly.mean.NW_top(timeIdx), 'r'); 
plot(0:36, hourly.mean.SE_top(timeIdx), 'r'); 
plot(0:36, hourly.mean.SW_top(timeIdx), 'r'); 

xlim([12 36]);
xlabel('Time [hr]');
ylabel('Temperature [C]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});



tempIndoor.mean = mean([hourly.mean.CT_low(timeIdx) ,hourly.mean.CT_mid(timeIdx) ,hourly.mean.CT_top(timeIdx), ...
    hourly.mean.NE_low(timeIdx) ,hourly.mean.NE_mid(timeIdx) ,hourly.mean.NE_top(timeIdx), ...
    hourly.mean.NW_low(timeIdx), hourly.mean.NW_mid(timeIdx), hourly.mean.NW_top(timeIdx), ...
    hourly.mean.SE_low(timeIdx), hourly.mean.SE_mid(timeIdx), hourly.mean.SE_top(timeIdx), ...
    hourly.mean.SW_low(timeIdx) ,hourly.mean.SW_mid(timeIdx), hourly.mean.SW_top(timeIdx)]');


tempIndoor.std = sqrt((...
    hourly.std.CT_top(timeIdx).^2 + (hourly.mean.CT_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.CT_mid(timeIdx).^2 + (hourly.mean.CT_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.CT_low(timeIdx).^2 + (hourly.mean.CT_low(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SE_top(timeIdx).^2 + (hourly.mean.SE_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SE_mid(timeIdx).^2 + (hourly.mean.SE_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SE_low(timeIdx).^2 + (hourly.mean.SE_low(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NE_top(timeIdx).^2 + (hourly.mean.NE_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NE_mid(timeIdx).^2 + (hourly.mean.NE_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NE_low(timeIdx).^2 + (hourly.mean.NE_low(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SW_top(timeIdx).^2 + (hourly.mean.SW_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SW_mid(timeIdx).^2 + (hourly.mean.SW_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SW_low(timeIdx).^2 + (hourly.mean.SW_low(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NW_top(timeIdx).^2 + (hourly.mean.NW_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NW_mid(timeIdx).^2 + (hourly.mean.NW_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NW_low(timeIdx).^2 + (hourly.mean.NW_low(timeIdx)-tempIndoor.mean').^2)/15)';
    
   

subplot(1,2,2); hold on
plot(0.5:36.5, tempIndoor.mean, 'b', 'linewidth',2);
plot(t_averaged+dt/2, T_indoor.mean, 'k', 'linewidth',2);
% plot(t_averaged+dt/2, T_indoor.mean-273.15, 'b', 'linewidth',2);

patch([0.5:36.5, fliplr(0.5:36.5)], [tempIndoor.mean+tempIndoor.std,  fliplr(tempIndoor.mean-tempIndoor.std)],[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.5);
% plot(0:36, tempIndoor.mean, 'b', 'linewidth',2);
xlim([12 36]);
ylim([16 30]);

% prediction
%%% hourly data
plot(t_averaged+dt/2, T_indoor.mean, 'k', 'linewidth',2);
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [T_indoor.ci_max,  fliplr(T_indoor.ci_min)],[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);

%%% minutely data
% patch([t_stamp' fliplr(t_stamp')], [max(data.temp_in) fliplr(min(data.temp_in))]-273.15,[0.8 0.8 0.8],...
%     'edgecolor','none','facealpha',0.5);
% plot(t_stamp, mean(data.temp_in)-273.15,'k','linewidth',2);

legend('Measurement','Prediction');
xlim([12 36]);
xlabel('Time');
ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});



% wall surface temperatures


figure();
subplot(1,2,1); hold on
% measurement
patch([0.5:36.5, fliplr(0.5:36.5)],...
    [hourly.mean.N_wall_in(timeIdx)'+hourly.std.N_wall_in(timeIdx)',...
    fliplr(hourly.mean.N_wall_in(timeIdx)'-hourly.std.N_wall_in(timeIdx)')],...
    [1.0 0.5 0.5],'edgecolor','none','facealpha',0.5);
plot(0.5:36.5, hourly.mean.N_wall_in(timeIdx), 'r');  

patch([0.5:36.5, fliplr(0.5:36.5)],...
    [hourly.mean.S_wall_in(timeIdx)'+hourly.std.S_wall_in(timeIdx)',...
    fliplr(hourly.mean.S_wall_in(timeIdx)'-hourly.std.S_wall_in(timeIdx)')],...
    [0.5 1.0 0.5],'edgecolor','none','facealpha',0.5);
plot(0.5:36.5, hourly.mean.S_wall_in(timeIdx), 'g');  

patch([0.5:36.5, fliplr(0.5:36.5)],...
    [hourly.mean.E_wall_in(timeIdx)'+hourly.std.E_wall_in(timeIdx)',...
    fliplr(hourly.mean.E_wall_in(timeIdx)'-hourly.std.E_wall_in(timeIdx)')],...
    [0.5 0.5 1.0],'edgecolor','none','facealpha',0.5);
plot(0.5:36.5, hourly.mean.E_wall_in(timeIdx), 'b');  

patch([0.5:36.5, fliplr(0.5:36.5)],...
    [hourly.mean.W_wall_in(timeIdx)'+hourly.std.W_wall_in(timeIdx)',...
    fliplr(hourly.mean.W_wall_in(timeIdx)'-hourly.std.W_wall_in(timeIdx)')],...
    [0.5 1.0 1.0],'edgecolor','none','facealpha',0.5);
plot(0.5:36.5, hourly.mean.W_wall_in(timeIdx), 'c');  


% prediction
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [T_wall_in.ci_max,  fliplr(T_wall_in.ci_min)],[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, T_wall_in.mean, 'k', 'linewidth',2);

%%% output result
% patch([t_stamp' fliplr(t_stamp')], [max(data.wall_in) fliplr(min(data.wall_in))]-273.15,[0.8 0.8 0.8],...
%     'edgecolor','none','facealpha',0.5);
% plot(t_stamp, mean(data.wall_in)-273.15,'k','linewidth',1.5);

title('Wall; inner surface temperature');
xlim([12 36]);      xlabel('Time'); 
ylim([14 28]);      ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});


subplot(1,2,2); hold on
% measurement
patch([0.5:36.5, fliplr(0.5:36.5)],...
    [hourly.mean.N_wall_out(timeIdx)'+hourly.std.N_wall_out(timeIdx)',...
    fliplr(hourly.mean.N_wall_out(timeIdx)'-hourly.std.N_wall_out(timeIdx)')],...
    [1.0 0.5 0.5],'edgecolor','none','facealpha',0.5);
plot(0.5:36.5, hourly.mean.N_wall_out(timeIdx), 'r');  

patch([0.5:36.5, fliplr(0.5:36.5)],...
    [hourly.mean.S_wall_out(timeIdx)'+hourly.std.S_wall_out(timeIdx)',...
    fliplr(hourly.mean.S_wall_out(timeIdx)'-hourly.std.S_wall_out(timeIdx)')],...
    [0.5 1.0 0.5],'edgecolor','none','facealpha',0.5);
plot(0.5:36.5, hourly.mean.S_wall_out(timeIdx), 'g');  


% prediction
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [T_wall_out.ci_max,  fliplr(T_wall_out.ci_min)],[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, T_wall_out.mean, 'k', 'linewidth',2);
% patch([t_stamp' fliplr(t_stamp')], [max(data.wall_out) fliplr(min(data.wall_out))]-273.15,[0.8 0.8 0.8],...
%     'edgecolor','none','facealpha',0.5);
% plot(t_stamp, mean(data.wall_out)-273.15,'k','linewidth',1.5);


title('Wall; outer surface temperature');
xlim([12 36]);      xlabel('Time'); 
ylim([14 28]);      ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});



% roof surface temperatures

figure();
subplot(1,2,1); hold on
% measurement
patch([0.5:36.5, fliplr(0.5:36.5)],...
    [hourly.mean.Roof_in(timeIdx)'+hourly.std.Roof_in(timeIdx)',...
    fliplr(hourly.mean.Roof_in(timeIdx)'-hourly.std.Roof_in(timeIdx)')],...
    [1.0 0.5 0.5],'edgecolor','none','facealpha',0.5);
plot(0.5:36.5, hourly.mean.Roof_in(timeIdx), 'r', 'linewidth',2);  


% prediction
%%% hourly
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [T_roof_in.ci_max,  fliplr(T_roof_in.ci_min)],[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, T_roof_in.mean, 'k', 'linewidth',2);

%%% minutely
% patch([t_stamp' fliplr(t_stamp')], [max(data.roof_in) fliplr(min(data.roof_in))]-273.15,[0.8 0.8 0.8],...
%     'edgecolor','none','facealpha',0.5);
% plot(t_stamp, mean(data.roof_in)-273.15,'k','linewidth',1.5);


title('Roof; inner surface temperature');
xlim([12 36]);      xlabel('Time'); 
ylim([10 60]);      ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});


subplot(1,2,2); hold on
% measurement
patch([0.5:36.5, fliplr(0.5:36.5)],...
    [hourly.mean.Roof_out(timeIdx)'+hourly.std.Roof_out(timeIdx)',...
    fliplr(hourly.mean.Roof_out(timeIdx)'-hourly.std.Roof_out(timeIdx)')],...
    [1.0 0.5 0.5],'edgecolor','none','facealpha',0.5);
plot(0.5:36.5, hourly.mean.Roof_out(timeIdx), 'r', 'linewidth',2);  
% prediction
%%% hourly
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [T_roof_out.ci_max,  fliplr(T_roof_out.ci_min)],[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, T_roof_out.mean, 'k', 'linewidth',2);


%%% minutely
% patch([t_stamp' fliplr(t_stamp')], [max(data.roof_out) fliplr(min(data.roof_out))]-273.15,[0.8 0.8 0.8],...
%     'edgecolor','none','facealpha',0.5);
% plot(t_stamp, mean(data.roof_out)-273.15,'k','linewidth',1.5);

title('Roof: outer surface temperature');
xlim([12 36]);      xlabel('Time'); 
ylim([10 60]);      ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});





%% ratio between components in single-sided ventilation model
% height:
%   skylight: 0.25, window:0.91, rear vent: 0.43, floor vent 0.09
data = sfv
R_buo  = 0.0035*mean(abs(data.temp_in-data.temp_out))*0.91;
R_wind = 0.001*mean(data.wind).^2;
R_turb = 0.01*ones(1,5400);
R_tot = R_buo+R_wind+R_turb;

figure(); hold on
plot(t_stamp, R_buo./R_tot, 'r');
plot(t_stamp, R_wind./R_tot, 'b');
plot(t_stamp, R_turb./R_tot, 'k');
legend('buoyancy', 'wind', 'turbulence');

axis([12 36 0 1]);
xlabel('Time');
ylabel('Ratio');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});
% figure();
% plot(t_stamp, mean(sv.temp_in - sv.temp_out));
% plot(t_stamp, mean(sv.wind));














%% ACH summary plot
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



