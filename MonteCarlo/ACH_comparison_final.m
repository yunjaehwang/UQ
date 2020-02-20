
load('/home/yunjaeh/github/UQ/MonteCarlo/ACH_day.mat');
load('/home/yunjaeh/github/UQ/MonteCarlo/ACH_night.mat');

% day time case
figure(1);
subplot(2,2,1); % s / fv
idExp = 1:2; hold on
for i=idExp
    plot([ACH_day.ACH(i,1), ACH_day.ACH(i,1)],[ACH_day.ACH_prediction_single(i,1), ACH_day.ACH_prediction_cross(i,1)],'k');
end
plot_single= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_single(idExp,1), ...
    ACH_day.ACH_prediction_single(idExp,2),ACH_day.ACH_prediction_single(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'bo','linewidth',1.5);
plot_cross= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_cross(idExp,1), ...
    ACH_day.ACH_prediction_cross(idExp,2),ACH_day.ACH_prediction_cross(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'ro','linewidth',1.5);


subplot(2,2,2); % s / v
idExp = 3:5; hold on
for i=idExp
    plot([ACH_day.ACH(i,1), ACH_day.ACH(i,1)],[ACH_day.ACH_prediction_single(i,1), ACH_day.ACH_prediction_cross(i,1)],'k');
end
plot_single= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_single(idExp,1), ...
    ACH_day.ACH_prediction_single(idExp,2),ACH_day.ACH_prediction_single(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'bo','linewidth',1.5);
plot_cross= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_cross(idExp,1), ...
    ACH_day.ACH_prediction_cross(idExp,2),ACH_day.ACH_prediction_cross(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'ro','linewidth',1.5);


subplot(2,2,3); % w / v
idExp = 6:7; hold on
for i=idExp
    plot([ACH_day.ACH(i,1), ACH_day.ACH(i,1)],[ACH_day.ACH_prediction_single(i,1), ACH_day.ACH_prediction_cross(i,1)],'k');
end
plot_single= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_single(idExp,1), ...
    ACH_day.ACH_prediction_single(idExp,2),ACH_day.ACH_prediction_single(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'bo','linewidth',1.5);
plot_cross= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_cross(idExp,1), ...
    ACH_day.ACH_prediction_cross(idExp,2),ACH_day.ACH_prediction_cross(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'ro','linewidth',1.5);

subplot(2,2,4); % s / w
idExp = 8:9; hold on
for i=idExp
    plot([ACH_day.ACH(i,1), ACH_day.ACH(i,1)],[ACH_day.ACH_prediction_single(i,1), ACH_day.ACH_prediction_cross(i,1)],'k');
end
plot_single= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_single(idExp,1), ...
    ACH_day.ACH_prediction_single(idExp,2),ACH_day.ACH_prediction_single(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'bo','linewidth',1.5);
plot_cross= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_cross(idExp,1), ...
    ACH_day.ACH_prediction_cross(idExp,2),ACH_day.ACH_prediction_cross(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'ro','linewidth',1.5);


for i=1:4
    subplot(2,2,i);
    plot_yx = plot(0:50, 0:50, 'k--','linewidth',1);
%     text(15, 15, 'y = x', 'BackgroundColor', 'w', 'rotation', 40, 'FontSize', 15);
xticks([0:5:50]);   xlabel('ACH: experiment');
yticks([0:5:50]);   ylabel('ACH: prediction');
grid on
axis([0 20 0 20])
end


% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
% % night time case
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

% figure(2);
subplot(2,2,1); % s / fv
idExp = 1:3; hold on
for i=idExp
    plot([ACH_night.ACH(i,1), ACH_night.ACH(i,1)],[ACH_night.ACH_prediction_single(i,1), ACH_night.ACH_prediction_cross(i,1)],'k');
end
plot_single= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_single(idExp,1), ...
    ACH_night.ACH_prediction_single(idExp,2),ACH_night.ACH_prediction_single(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'bo','linewidth',1.5);
plot_cross= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_cross(idExp,1), ...
    ACH_night.ACH_prediction_cross(idExp,2),ACH_night.ACH_prediction_cross(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'ro','linewidth',1.5);


subplot(2,2,2); % s / v
idExp = 4:5; hold on
for i=idExp
    plot([ACH_night.ACH(i,1), ACH_night.ACH(i,1)],[ACH_night.ACH_prediction_single(i,1), ACH_night.ACH_prediction_cross(i,1)],'k');
end
plot_single= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_single(idExp,1), ...
    ACH_night.ACH_prediction_single(idExp,2),ACH_night.ACH_prediction_single(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'bo','linewidth',1.5);
plot_cross= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_cross(idExp,1), ...
    ACH_night.ACH_prediction_cross(idExp,2),ACH_night.ACH_prediction_cross(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'ro','linewidth',1.5);


subplot(2,2,3); % w / v
idExp = 6:7; hold on
for i=idExp
    plot([ACH_night.ACH(i,1), ACH_night.ACH(i,1)],[ACH_night.ACH_prediction_single(i,1), ACH_night.ACH_prediction_cross(i,1)],'k');
end
plot_single= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_single(idExp,1), ...
    ACH_night.ACH_prediction_single(idExp,2),ACH_night.ACH_prediction_single(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'bo','linewidth',1.5);
plot_cross= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_cross(idExp,1), ...
    ACH_night.ACH_prediction_cross(idExp,2),ACH_night.ACH_prediction_cross(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'ro','linewidth',1.5);

subplot(2,2,4); % s / w
idExp = 8:10; hold on
for i=idExp
    plot([ACH_night.ACH(i,1), ACH_night.ACH(i,1)],[ACH_night.ACH_prediction_single(i,1), ACH_night.ACH_prediction_cross(i,1)],'k');
end
plot_single= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_single(idExp,1), ...
    ACH_night.ACH_prediction_single(idExp,2),ACH_night.ACH_prediction_single(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'bo','linewidth',1.5);
plot_cross= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_cross(idExp,1), ...
    ACH_night.ACH_prediction_cross(idExp,2),ACH_night.ACH_prediction_cross(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'ro','linewidth',1.5);


for i=1:4
    subplot(2,2,i);
    plot_yx = plot(0:50, 0:50, 'k--','linewidth',1);
%     text(15, 15, 'y = x', 'BackgroundColor', 'w', 'rotation', 40, 'FontSize', 15);
xticks([0:5:50]);   xlabel('ACH: experiment');
yticks([0:5:50]);   ylabel('ACH: prediction');
grid on
axis([0 20 0 20])
end

%% single and cross separate


load('/home/yunjaeh/github/UQ/MonteCarlo/ACH_day.mat');
load('/home/yunjaeh/github/UQ/MonteCarlo/ACH_night.mat');

% day time case
figure(101);
subplot(2,2,1); % s / fv
idExp = 1:2; hold on
plot_single= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_single(idExp,1), ...
    ACH_day.ACH_prediction_single(idExp,2),ACH_day.ACH_prediction_single(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'bo','linewidth',1.5);
idExp = 1:3; 
plot_single= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_single(idExp,1), ...
    ACH_night.ACH_prediction_single(idExp,2),ACH_night.ACH_prediction_single(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'bo','linewidth',1.5);

subplot(2,2,2); % s / v
idExp = 3:5; hold on
plot_single= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_single(idExp,1), ...
    ACH_day.ACH_prediction_single(idExp,2),ACH_day.ACH_prediction_single(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'bo','linewidth',1.5);
idExp = 4:5;
plot_single= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_single(idExp,1), ...
    ACH_night.ACH_prediction_single(idExp,2),ACH_night.ACH_prediction_single(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'bo','linewidth',1.5);


subplot(2,2,3); % w / v
idExp = 6:7; hold on
plot_single= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_single(idExp,1), ...
    ACH_day.ACH_prediction_single(idExp,2),ACH_day.ACH_prediction_single(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'bo','linewidth',1.5);
idExp = 6:7;
plot_single= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_single(idExp,1), ...
    ACH_night.ACH_prediction_single(idExp,2),ACH_night.ACH_prediction_single(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'bo','linewidth',1.5);


subplot(2,2,4); % s / w
idExp = 8:9; hold on
plot_single= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_single(idExp,1), ...
    ACH_day.ACH_prediction_single(idExp,2),ACH_day.ACH_prediction_single(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'bo','linewidth',1.5);
idExp = 8:10; 
plot_single= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_single(idExp,1), ...
    ACH_night.ACH_prediction_single(idExp,2),ACH_night.ACH_prediction_single(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'bo','linewidth',1.5);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure(102);
subplot(2,2,1); % s / fv
idExp = 1:2; hold on
plot_cross= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_cross(idExp,1), ...
    ACH_day.ACH_prediction_cross(idExp,2),ACH_day.ACH_prediction_cross(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'ro','linewidth',1.5);
idExp = 1:3; 
plot_cross= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_cross(idExp,1), ...
    ACH_night.ACH_prediction_cross(idExp,2),ACH_night.ACH_prediction_cross(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'ro','linewidth',1.5);

subplot(2,2,2); % s / v
idExp = 3:5; hold on
plot_cross= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_cross(idExp,1), ...
    ACH_day.ACH_prediction_cross(idExp,2),ACH_day.ACH_prediction_cross(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'ro','linewidth',1.5);
idExp = 4:5;
plot_cross= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_cross(idExp,1), ...
    ACH_night.ACH_prediction_cross(idExp,2),ACH_night.ACH_prediction_cross(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'ro','linewidth',1.5);


subplot(2,2,3); % w / v
idExp = 6:7; hold on
plot_cross= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_cross(idExp,1), ...
    ACH_day.ACH_prediction_cross(idExp,2),ACH_day.ACH_prediction_cross(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'ro','linewidth',1.5);
idExp = 6:7;
plot_cross= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_cross(idExp,1), ...
    ACH_night.ACH_prediction_cross(idExp,2),ACH_night.ACH_prediction_cross(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'ro','linewidth',1.5);


subplot(2,2,4); % s / w
idExp = 8:9; hold on
plot_cross= errorbar(ACH_day.ACH(idExp,1), ACH_day.ACH_prediction_cross(idExp,1), ...
    ACH_day.ACH_prediction_cross(idExp,2),ACH_day.ACH_prediction_cross(idExp,3),...
    ACH_day.ACH(idExp,2), ACH_day.ACH(idExp,2), 'ro','linewidth',1.5);
idExp = 8:10; 
plot_cross= errorbar(ACH_night.ACH(idExp,1), ACH_night.ACH_prediction_cross(idExp,1), ...
    ACH_night.ACH_prediction_cross(idExp,2),ACH_night.ACH_prediction_cross(idExp,3),...
    ACH_night.ACH(idExp,2), ACH_night.ACH(idExp,2), 'ro','linewidth',1.5);




for j=101:102
    figure(j);
for i=1:4
    subplot(2,2,i);
    plot_yx = plot(0:50, 0:50, 'k--','linewidth',1);
%     text(15, 15, 'y = x', 'BackgroundColor', 'w', 'rotation', 40, 'FontSize', 15);
xticks([0:5:50]);   xlabel('ACH: experiment');
yticks([0:5:50]);   ylabel('ACH: prediction');
grid on
axis([0 25 0 25])
end
end


figure(102);
subplot(2,2,4);
plot_yx = plot(0:50, 0:50, 'k--','linewidth',1);
xticks([0:5:50]);   xlabel('ACH: experiment');
yticks([0:20:100]);   ylabel('ACH: prediction');
grid on
axis([0 25 0 100])




