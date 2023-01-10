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

## 添加STC头文件到Keil中

- 打开STC-ISP，在右侧的选项卡中有个 `Keil仿真设置`
- 点击该按钮，选择keil安装目录，再按确定即可

![add stc mcu](./docs/add%20stc%20mcu.png)
![add stc mcu success](./docs/add%20stc%20mcu%20success.png)

## VSCode的配置文件

[c_cpp_properties.json#L6](./.vscode/c_cpp_properties.json#L6)

`c_cpp_properties.json`中的 `includePath`字段为头文件包含路径，其中指向keil头文件的路径需要改为你电脑上实际的安装路径

例如，我电脑上为：`C:\Keil_v5`，需要将反撇号改为正撇号，再加上一串路径，最后为：`C:/Keil_v5/C51/INC/**`

## 将Keil中的文件编码格式改为GB2312

不论是否发生乱码，请都将keil的编码格式改为GB2312（仅为本项目）

左上角 `Edit`，然后是 `Configuration..`，第一个选项卡 `Editor`

![switch keil encode to utf8](./docs/switch%20keil%20encode%20to%20gb2312.png)
