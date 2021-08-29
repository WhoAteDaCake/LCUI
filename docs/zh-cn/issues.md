# 问题解决记录

## libui、libplatform、libapp 互相依赖，如何解耦？

解决方案：

- libui:
  - 提供一个函数用于被动处理事件，不再主动调用 libapp 的事件绑定方法。
  - 将 textview、button、anchor、scrollbar 等基础组件拆分为独立库。
- libplatform:
- libapp:

## 全局 settings 数据如何解耦？

## 图片加载器与组件如何解耦？

现存问题：

- 图片加载器与组件存在耦合：图片缓存采用组件作为索引，图片加载函数依赖组件的样式表
- 图片加载任务依赖主循环提供的函数实现异步加载

解决方案：

- 图片加载器与组件之间采用事件进行通信，组件主动监听事件，图片加载器在图片加载完时触发事件
- 分配一个工作线程负责图片加载任务，任务完成后追加到图片加载器的事件队列中
- 图片加载器提供事件处理函数