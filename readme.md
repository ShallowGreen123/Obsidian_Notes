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


|           Frequency setting description           | [docs](./hardware/TX_AH/泰芯802.11AH%20Frequency%20setting%20description_20231130110312.pdf)                       |
|:-------------------------------------------------:|:------------------------------------------------------------------------------------------------------------------ |
| TX-AH-Rx00P Series module technical specification | [docs](./hardware/TX_AH/泰芯802.11ah TX-AH-Rx00P%20Series%20module%20technical%20specification_20231116174457.pdf) |
|          TX-AH-Rx00P Bridge instructions          | [docs](./hardware/TX_AH//泰芯AH%20Bridge%20instructions_20230908122753.pdf)                                        |
|    AH Module AT instruction development guide     | [docs](./hardware/TX_AH/泰芯AH%20Module%20AT%20instruction%20development%20guide_20230524100503.pdf)               |
|     AH Module development board instructions      | [docs](./hardware/TX_AH/泰芯AH%20Module%20development%20board%20instructions_20230621205234.pdf)                   |
|          AH Module hardware Design Guide          | [docs](./hardware/TX_AH/泰芯AH%20Module%20hardware%20Design%20Guide_20230621170639.pdf)                            |
|            AH Performance test method             | [docs](./hardware/TX_AH/泰芯AH%20Performance%20test%20method_20230908122816.pdf)                                   |
|           AH-RF EMC Certification guide           | [docs](./hardware/TX_AH/泰芯AH-RF EMC%20Certification%20guide_20230720140052.pdf)                                  |
