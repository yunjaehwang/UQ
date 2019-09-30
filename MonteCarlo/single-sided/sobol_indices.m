% This code is to compute Sobol indices
% of UQ simulations

% cler space and load output data
clear;  clc;
load('./data_summary.mat');
load('/home/yunjaeh/OpenFOAM/yunjaeh-4.0/run/UQ/uq_2019/integral_time_stamp.mat');     % load time stamp

%% --------------------------------------------------------------------- %%
% uncertain input parameters
numParam   = 14;        % # of uncertain parameters
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
% infiltration range
% avg of min, mean, max: 3.9487, 4.3925, 4.8275
% min(min), max(max): 3.27, 5.94
up( 11,1) = 3.27;        up( 11,2) = 5.94;    % Infiltration
up( 12,1) = -1.0;        up( 12,2) = 1.0;    % Temperature std
up( 13,1) = -1.0;        up( 13,2) = 1.0;    % Radiation std
up( 14,1) = -1.0;        up( 14,2) = 1.0;    % Wind std 


%% --------------------------------------------------------------------- %%
% quantity of interest: could be tempeature, ACH, ...
qoi = data.vent_rate;
var_total =  var(qoi);
sobolIndices = zeros(numParam,3377);

for p = 1:numParam
    % divide the range of uncertain paramter into N windows
    dimSpace = 80;
    xSpace = linspace(up(p,1), up(p,2), dimSpace+1);
%     idx_space = zeros(dim_space,size(input_data,2));
    var_save = zeros(3377,dimSpace);
    for i=1:dimSpace
        idx_space = (xSpace(i) <= data.input(:,p)) & (xSpace(i+1) > data.input(:,p)); 
        var_save(:,i) =  mean(qoi(idx_space,:))';
    end
    sobolIndices(p,:) = var(var_save')./var_total;
end

mean(sum(sobolIndices))

%% --------------------------------------------------------------------- %%
% plot sobol indices
figure();
hold on
% for p=1:numParam
% for p=1:7
for p=8:14
   plot(t_stamp, sobolIndices(p,:),'linewidth',2);
end
% legend('h_{in}', 'h_{out}', 'k_{roof}', 'k_{wall}', '\epsilon_{roof}','\epsilon_{wall}','Absorptivity',...

legend('Coefficient1','Coefficient2','Coefficient3',...
      'Infiltration','Temp std','Rad std','Wind std',...
'location','eastoutside');    

    

xlim([0 24]);      ylim([0 1.0]);
xlabel('Time [hr]');    ylabel('Sobol index'); 
xticks(12:12:36);   xticklabels({'Noon','Midnight','Noon'});
title('Sobol indices');


%% --------------------------------------------------------------------- %%
% convergence of statistics (mean and std)
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




