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
