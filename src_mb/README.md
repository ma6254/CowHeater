# Source CowHeater_MB

芯片: `STC8H8K64U`(`TSSOP20`)
烧录文件: `Objects/cowheater_mb.hex`

## 引脚定义

| Name     | Pin | GPIO     | Description                |
| -------- | --- | -------- | -------------------------- |
| LED      | 5   | P13      | 测试用的，接LED负极        |
| UART1_RX | 11  | P30/RxD  | STC-ISP烧录口，UART1_RX    |
| UART1_TX | 12  | P31/TxD  | STC-ISP烧录口，UART1_TX    |
| I2C_SCL  | 2   | P15      | 预留，接I2C器件SCL         |
| I2C_SDA  | 1   | P14      | 预留，接I2C器件SDA         |
| HEAT     | 20  | P10      | 可控硅控制脚               |
| TEMP     | 19  | P11/ADC1 | 热床温度，热电偶信号采样脚 |

## 目录

```plaintext
├─.vscode       # VSCode配置
├─Objects       # 编译生成
└─Sources       # 源代码
    ├─app       # 应用层代码
    │  └─main.c # 程序入口
    └─stc_hal   # STC寄存器驱动
```
