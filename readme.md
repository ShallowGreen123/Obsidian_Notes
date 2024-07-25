- feat - 新功能 feature
- fix - 修复 bug
- docs - 文档注释
- style - 代码格式(不影响代码运行的变动)
- refactor - 重构、优化(既不增加新功能，也不是修复bug)
- perf - 性能优化
- test - 增加测试
- chore - 构建过程或辅助工具的变动
- revert - 回退
- build - 打包

Dylan1

|                          AT cmd                          |           Help           |
| :------------------------------------------------------: | :----------------------: |
|                            AT                            |       Sample test        |
|                           AT?                            |         Get help         |
|                         AT+VER?                          |       Get ver help       |
|                         AT+VER=?                         |       Run get ver        |
|                        AT+TCONF?                         |     Get config help      |
|                        AT+TCONF=?                        |      Run get config      |
|    AT+TCONF=868000000:22:4:12:4/5:0:0:1:16:25000:2:3     |     Modulation LORA      |
| AT+TCONF=868000000:22:10000:10000:4/5:0:0:3:16:25000:2:3 |      Modulation FSK      |
| AT+TCONF=868000000:22:50000:50000:4/5:0:0:0:16:25000:2:3 |      Modulation MSK      |
|                         AT+TTONE                         |    Start RF Tone test    |
|                         AT+TRSSI                         | Starts RF RSSI tone test |
|                        AT+TTX=10                         | Set the number of tests  |


|        模组名称        |     正面丝印区分     |    过认证情况     |                       备注                        |
| :----------------: | :------------: | :----------: | :---------------------------------------------: |
|    TX-AH-R900P     | 左下角 P9，右下角 P9  | 可过 FCC/CE 认证 |             支持 860MHz ~  <br>928MHz             |
|   TX-AH-R900PNR    | 左下角 P9， 右下角 NR |  可过 FCC 认证   | 支持 902MHz ~  <br>928MHz， 带 915M Saw  <br>改善接收性能 |
| TX-AH-R900PNR-860M | 左下角 86， 右下角 NR |   可过 CE 认证   | 支持 859MHz ~  <br>894MHz， 带 875M Saw  <br>改善接收性能 |
