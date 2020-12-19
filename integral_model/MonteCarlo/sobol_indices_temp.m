% This code is to compute Sobol indices
% of UQ simulations

% cler space and load output data
clear;  clc;

% load timestamp
load('/home/yunjaeh/github/UQ/MonteCarlo/cross/time_stamp4.mat');

% load single-sided ventilation prediction data
load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/data_v6.temp/sfv/data_summary.mat');   single_sfv = data;
load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/data_v6.temp/sv/data_summary.mat');   single_sv = data;
load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/data_v6.temp/wv/data_summary.mat');   single_wv = data;
load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/data_v6.temp/sw/data_summary.mat');   single_sw = data;


% load cross-ventilation prediction data
load('/home/yunjaeh/github/UQ/MonteCarlo/cross/data_v6.temp/sfv/data_summary.mat');          cross_sfv = data;
load('/home/yunjaeh/github/UQ/MonteCarlo/cross/data_v6.temp/sv/data_summary.mat');          cross_sv = data;
load('/home/yunjaeh/github/UQ/MonteCarlo/cross/data_v6.temp/wv/data_summary.mat');          cross_wv = data;
load('/home/yunjaeh/github/UQ/MonteCarlo/cross/data_v6.temp/sw/data_summary.mat');          cross_sw = data;


%% --------------------------------------------------------------------- %%
numParam = 9;        % # of uncertain parameters

% dt = 1.0;
dt = 0.5;
t_averaged = 0:dt:(27-dt);

% uncertain input parameters
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


% qoi = singleData.vent_rate;
t_length = length(t_stamp);
qoi_sfv = single_sfv.temp_in;
qoi_sv  = single_sv.temp_in;
qoi_wv  = single_wv.temp_in;
qoi_sw  = single_sw.temp_in;

var_total_sfv =  var(qoi_sfv);
var_total_sv =  var(qoi_sv);
var_total_wv =  var(qoi_wv);
var_total_sw =  var(qoi_sw);

SI_single_sfv = zeros(numParam,t_length);
SI_single_sv = zeros(numParam,t_length);
SI_single_wv = zeros(numParam,t_length);
SI_single_sw = zeros(numParam,t_length);

for p = 1:numParam
    % divide the range of uncertain paramter into N windows
    dimSpace = 60;
    xSpace = linspace(up(p,1), up(p,2), dimSpace+1);
%     idx_space = zeros(dim_space,size(input_data,2));
    var_save1 = zeros(t_length,dimSpace);
    var_save2 = zeros(t_length,dimSpace);
    var_save3 = zeros(t_length,dimSpace);
    var_save4 = zeros(t_length,dimSpace);
    for i=1:dimSpace
        idx_space = (xSpace(i) <= single_sfv.input(:,p)) & (xSpace(i+1) > single_sfv.input(:,p)); 
        var_save1(:,i) =  mean(qoi_sfv(idx_space,:))';
        idx_space = (xSpace(i) <= single_sv.input(:,p)) & (xSpace(i+1) > single_sv.input(:,p)); 
        var_save2(:,i) =  mean(qoi_sv(idx_space,:))';
        idx_space = (xSpace(i) <= single_wv.input(:,p)) & (xSpace(i+1) > single_wv.input(:,p)); 
        var_save3(:,i) =  mean(qoi_wv(idx_space,:))';
        idx_space = (xSpace(i) <= single_sw.input(:,p)) & (xSpace(i+1) > single_sw.input(:,p)); 
        var_save4(:,i) =  mean(qoi_sw(idx_space,:))';
    end
    SI_single_sfv(p,:) = var(var_save1')./var_total_sfv;
    SI_single_sv(p,:) = var(var_save2')./var_total_sv;
    SI_single_wv(p,:) = var(var_save3')./var_total_wv;
    SI_single_sw(p,:) = var(var_save4')./var_total_sw;
end

% day
idx_day      = (t_stamp > 3  & t_stamp < 6 ) | (t_stamp > 24 );
idx_night    = (t_stamp > 12  & t_stamp < 18 );


%
% plot(mean(SI_single_sfv(:,idx_night)','omitnan') ,'b<');
% plot(mean(SI_single_sv(:,idx_night)','omitnan') ,'bo');
% plot(mean(SI_single_wv(:,idx_night)','omitnan') ,'bs');
% plot(mean(SI_single_sw(:,idx_night)','omitnan') ,'bx');



%% bar plot, stacked
figure();
subplot(1,2,1);
barh([mean(SI_single_sfv(:,idx_day)'); mean(SI_single_sv(:,idx_day)');...
    mean(SI_single_wv(:,idx_day)');mean(SI_single_sw(:,idx_day)')],'stacked');

subplot(1,2,2);
barh([mean(SI_single_sfv(:,idx_night)'); mean(SI_single_sv(:,idx_night)');...
    mean(SI_single_wv(:,idx_night)');mean(SI_single_sw(:,idx_night)')],'stacked');



%% --------------------------------------------------------------------- %%
% uncertain input parameters
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



% qoi = singleData.vent_rate;
t_length = length(t_stamp);
qoi_sfv = cross_sfv.temp_in;
qoi_sv  = cross_sv.temp_in;
qoi_wv  = cross_wv.temp_in;
qoi_sw  = cross_sw.temp_in;

var_total_sfv =  var(qoi_sfv);
var_total_sv =  var(qoi_sv);
var_total_wv =  var(qoi_wv);
var_total_sw =  var(qoi_sw);

SI_cross_sfv = zeros(numParam,t_length);
SI_cross_sv = zeros(numParam,t_length);
SI_cross_wv = zeros(numParam,t_length);
SI_cross_sw = zeros(numParam,t_length);

for p = 1:numParam
    % divide the range of uncertain paramter into N windows
    dimSpace = 60;
    xSpace = linspace(up(p,1), up(p,2), dimSpace+1);
%     idx_space = zeros(dim_space,size(input_data,2));
    var_save1 = zeros(t_length,dimSpace);
    var_save2 = zeros(t_length,dimSpace);
    var_save3 = zeros(t_length,dimSpace);
    var_save4 = zeros(t_length,dimSpace);
    for i=1:dimSpace
        idx_space = (xSpace(i) <= cross_sfv.input(:,p)) & (xSpace(i+1) > cross_sfv.input(:,p)); 
        var_save1(:,i) =  mean(qoi_sfv(idx_space,:))';
        idx_space = (xSpace(i) <= cross_sv.input(:,p)) & (xSpace(i+1) > cross_sv.input(:,p)); 
        var_save2(:,i) =  mean(qoi_sv(idx_space,:))';
        idx_space = (xSpace(i) <= cross_wv.input(:,p)) & (xSpace(i+1) > cross_wv.input(:,p)); 
        var_save3(:,i) =  mean(qoi_wv(idx_space,:))';
        idx_space = (xSpace(i) <= cross_sw.input(:,p)) & (xSpace(i+1) > cross_sw.input(:,p)); 
        var_save4(:,i) =  mean(qoi_sw(idx_space,:))';
    end
    SI_cross_sfv(p,:) = var(var_save1')./var_total_sfv;
    SI_cross_sv(p,:) = var(var_save2')./var_total_sv;
    SI_cross_wv(p,:) = var(var_save3')./var_total_wv;
    SI_cross_sw(p,:) = var(var_save4')./var_total_sw;
end

% day
idx_day      = (t_stamp > 3  & t_stamp < 6 ) | (t_stamp > 24 );
idx_night    = (t_stamp > 12  & t_stamp < 18 );


%% figures

figure();
subplot(4,2,1); boxplot(SI_cross_sfv(:,idx_day)'); yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,3); boxplot(SI_cross_sv(:,idx_day)');  yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,5); boxplot(SI_cross_wv(:,idx_day)');  yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,7); boxplot(SI_cross_sw(:,idx_day)');  yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on


subplot(4,2,2); boxplot(SI_single_sfv(:,idx_day)'); yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,4); boxplot(SI_single_sv(:,idx_day)');  yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,6); boxplot(SI_single_wv(:,idx_day)'); yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,8); boxplot(SI_single_sw(:,idx_day)'); yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on



figure();
subplot(4,2,1); boxplot(SI_cross_sfv(:,idx_night)');   yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,3); boxplot(SI_cross_sv(:,idx_night)');    yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,5); boxplot(SI_cross_wv(:,idx_night)');    yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,7); boxplot(SI_cross_sw(:,idx_night)');    yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on

subplot(4,2,2); boxplot(SI_single_sfv(:,idx_night)'); yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,4); boxplot(SI_single_sv(:,idx_night)');  yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,6); boxplot(SI_single_wv(:,idx_night)');  yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on
subplot(4,2,8); boxplot(SI_single_sw(:,idx_night)');  yticks(0:0.5:1.0);  ylim([0 1.0]);  ylabel(''); yticklabels(''); xticklabels(''); grid on





%% all boxplot in one plot
group = [ 1:10:71,  2:10:72, 3:10:73, 4:10:74, 5:10:75];

figure();
subplot(2,1,1); hold on
boxplot([SI_cross_sfv(:,idx_day)', SI_cross_sv(:,idx_day)',...
    SI_cross_wv(:,idx_day)', SI_cross_sw(:,idx_day)', zeros(900,8)-1],group)
 for i=1:7
        plot([5*i, 5*i], [0 1],'k')
 end

xlim([0 40]);
xticks([]);
yticks(0:0.2:1.0);
ylim([0 1.0]);
ylabel('Sobol index');


    
subplot(2,1,2); hold on
boxplot([SI_cross_sfv(:,idx_night)', SI_cross_sv(:,idx_night)',...
    SI_cross_wv(:,idx_night)', SI_cross_sw(:,idx_night)', zeros(899,8)-1],group)
 for i=1:7
        plot([5*i, 5*i], [0 1],'k')
    end
xlim([0 40]);
xticks([]);
yticks(0:0.2:1.0);
ylim([0 1.0]);


%% --------------------------------------------------------------------- %%
for Sobol_index_time_series = 0
numParam = 9;        % # of uncertain parameters

% dt = 1.0;
dt = 0.5;
t_averaged = 0:dt:(27-dt);
SI_single_avg = zeros(numParam,length(t_averaged));


% uncertain input parameters
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



% quantity of interest: could be tempeature, ACH, ...
t_length = length(t_stamp);
ach = singleData.vent_rate;


% qoi = singleData.vent_rate;
qoi = singleData.temp_in;
% qoi = ach;
% qoi = data.wall_out;

var_total =  var(qoi);
SI_single = zeros(numParam,t_length);

for p = 1:numParam
    % divide the range of uncertain paramter into N windows
    dimSpace = 80;
    xSpace = linspace(up(p,1), up(p,2), dimSpace+1);
%     idx_space = zeros(dim_space,size(input_data,2));
    var_save = zeros(t_length,dimSpace);
    for i=1:dimSpace
        idx_space = (xSpace(i) <= singleData.input(:,p)) & (xSpace(i+1) > singleData.input(:,p)); 
        var_save(:,i) =  mean(qoi(idx_space,:))';
    end
    SI_single(p,:) = var(var_save')./var_total;
    
    for i= 1:length(t_averaged)
        idx = t_averaged(i) < t_stamp & t_stamp < (t_averaged(i)+dt);
        SI_single_avg(p,i) = mean(SI_single(p,idx));
    end
end


figure();
hold on
plot(t_averaged, SI_single_avg(1,:),'b<-','linewidth',2);
plot(t_averaged, SI_single_avg(2,:),'b<:','linewidth',2);
plot(t_averaged, SI_single_avg(3,:),'ro-','linewidth',2);
plot(t_averaged, SI_single_avg(4,:),'ro:','linewidth',2);
plot(t_averaged, SI_single_avg(5,:),'gx-','linewidth',2);
plot(t_averaged, SI_single_avg(6,:),'gx:','linewidth',2);
plot(t_averaged, SI_single_avg(7,:),'k-','linewidth',2);
plot(t_averaged, SI_single_avg(8,:),'k:','linewidth',2);
plot(t_averaged, SI_single_avg(9,:),'k--','linewidth',2);

legend('h_{in}', 'h_{out}','\rho_{roof}','\epsilon_{roof}','C_1','C_2',...
     'p_{temp}','p_{rad}','p_{wind}','location','eastoutside');  
legend boxoff
xlim([3 27]);     
xticks(3:12:27);
xticklabels({'Noon','Midnight','Noon'});
yticks(0:0.2:1.0);
ylim([0 1.0]);
ylabel('Sobol index');



%% --------------------------------------------------------------------- %%
% uncertain input parameters
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


% quantity of interest: could be tempeature, ACH, ...
t_length = length(t_stamp);
ach = crossData.vent_rate;


% qoi = singleData.vent_rate;
qoi = crossData.temp_in;
% qoi = ach;
% qoi = data.wall_out;

var_total =  var(qoi);
SI_cross = zeros(numParam,t_length);

for p = 1:numParam
    % divide the range of uncertain paramter into N windows
    dimSpace = 80;
    xSpace = linspace(up(p,1), up(p,2), dimSpace+1);
    if(p==5)
       xSpace(1:dimSpace/2) = linspace(-up(p,2), -up(p,1), dimSpace/2);
       xSpace(dimSpace/2+1 : dimSpace+1) = linspace(up(p,1), up(p,2), dimSpace/2+1);
    end
%     idx_space = zeros(dim_space,size(input_data,2));
    var_save = zeros(t_length,dimSpace);
    for i=1:dimSpace
        idx_space = (xSpace(i) <= crossData.input(:,p)) & (xSpace(i+1) > crossData.input(:,p)); 
        var_save(:,i) =  mean(qoi(idx_space,:))';
    end
    SI_cross(p,:) = var(var_save','omitnan')./var_total;
    
    for i= 1:length(t_averaged)
        idx = t_averaged(i) < t_stamp & t_stamp < (t_averaged(i)+dt);
        SI_cross_avg(p,i) = mean(SI_cross(p,idx));
    end
end



figure();
hold on
plot(t_averaged, SI_cross_avg(1,:),'b<-','linewidth',2);
plot(t_averaged, SI_cross_avg(2,:),'b<:','linewidth',2);
plot(t_averaged, SI_cross_avg(3,:),'ro-','linewidth',2);
plot(t_averaged, SI_cross_avg(4,:),'ro:','linewidth',2);
plot(t_averaged, SI_cross_avg(5,:),'gx-','linewidth',2);
% plot(t_averaged, SI_single_avg(6,:),'gx:','linewidth',2);
plot(t_averaged, SI_cross_avg(6,:),'k-','linewidth',2);
plot(t_averaged, SI_cross_avg(7,:),'k:','linewidth',2);
plot(t_averaged, SI_cross_avg(8,:),'k--','linewidth',2);

legend('h_{in}', 'h_{out}','\rho_{roof}','\epsilon_{roof}','\DeltaC_p',...
     'p_{temp}','p_{rad}','p_{wind}','location','eastoutside');  
legend boxoff
xlim([3 27]);      
xticks(3:12:27);
xticklabels({'Noon','Midnight','Noon'});

yticks(0:0.2:1.0);
ylim([0 1.0]);
ylabel('Sobol index');
end




