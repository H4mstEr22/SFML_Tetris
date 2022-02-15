# SFML_Tetris

### 介绍

已经实现SRS旋转，7bag，4next，T-Spin判定，BackToBack判定，PerfectClear(全消)判定。

音效素材使用的是puyopuyoTetris的音效。

### 代码位置

SFML Tetris/源.cpp

### 自定义设置

#### 时间

630行开始的变量：

- 左右下长按连续移动延迟: leftswitchtime, rightswitchtime, downswitchtime  值越大延迟越高
- 左右连续移动速度: holdtime  值越大移动速度越慢
- 自动下落速度: gswitchtime

#### 按键

737行的循环中，原设置如下

- 左右移动 L/R Move: A D
- 软降 Soft Drop: S
- 硬降 Hard Drop: W
- 顺时针旋转 Clockwise Rotate: ↑
- 逆时针旋转 Counterclockwise Rotate: ↓
- 重新开始 Restart: R