
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




