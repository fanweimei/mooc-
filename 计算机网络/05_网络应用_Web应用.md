
1. Web应用(World Wide Web)
    - Web
        - 网页
            - 多个对象：HTML文件、图片、视频文件、脚本等
            - 对象的寻址
                - URL：统一资源定位符
                - Scheme://host:port/path
        - 网页互连
    - HTTP协议
        - 超文本传输协议(HyperText Transfer Protocol)
        - C/S结构
        - HTTP版本
            - 1.0
            - 1.1
        - 使用TCP传输服务
        - 无状态
2. HTTP连接
    - 非持久性连接
        - 每个TCP连接最多允许传输一个对象
        - HTTP1.0版本使用非持久性连接
        - 响应时间分析与建模
            - 发起、建立TCP连接：1个RTT
            - 发送HTTP请求消息到HTTP响应消息的前几个字节：1RTT
            - 响应消息中所含的文件/对象传输时间
            - RTT(Round Trip Time)：从客户端发送一个很小的数据包到服务器并返回所经历的时间
            - 响应时间：2RTT+文件发送时间
        - 非持久性连接的问题
            - 每个对象需要2个RTT
            - 操作系统需要为每个TCP连接开销资源
            - 浏览器怎么做？
                - 打开多个并行的TCP连接以获取网页所需对象
                - 给服务器造成的影响？
    - 持久性连接
        - 每个TCP允许传输多个对象
        - HTTP1.1版本默认使用持久性连接
        - 分类
            - 无流水的持久性连接
                - 客户端只有收到前一个响应后才发送新的请求
                - 每个被应用的对象耗时1RTT
            - 带有流水机制的持久性连接
                - HTTP1.1默认选项
                - 客户端只要遇到一个引用对象就尽快发出请求
                - 理性情况，收到所有的引用对象只需要耗时约1个RTT
3. HTTP消息格式
    - 请求消息
        ```
            GET /somedir/page.html HTTP/1.0  //请求行：请求方法、URL、HTTP版本
            Host: www.someschool.edu         // 请求头，缓存功能需要使用
            User-agent: Mozilla/4.0           
            Connection: close
            Accept-language: fr
                                            // 空行
                                            // 请求体
        ```
        - 方法的类型
            - HTTP/1.0
                - GET
                - POST
                - HEAD
            - HTTP/1.1
                - GET
                - POST
                - HEAD
                - PUT
                - DELETE
    - 响应消息
        ```
            HTTP/1.1 200 ok       // 状态行：协议 状态码 
            Connection: close     // 响应头
            Date: Thu, 06 Aug 1998 12:00:15 GMT
            Server: Apache/1.3.0(Unix)
            Last-Modified: Mon, 22 Jun 1998...
            Content-Length: 6821
                                      //空行
        ```
        - 响应状态码
            - 200 ok
            - 301 Move Permanently
            - 400 Bad Request
            - 404 Not Found
            - 505 HTTP Version Not Supported
4. Cookie技术
    - 某些网站为了辨别用户身份、进行session跟踪而存储在用户本地终端上的数据。
    - Cookie组件
        - HTTP响应消息的cookie头部行
        - HTTP请求消息的cookie头部行
        - 保存在客户端主机上的cookie文件，由浏览器管理
        - Web服务器的后台管理
    - Cookie作用
        - 身份认证
        - 购物车
        - 推荐
        - Web email
    - 隐私问题
5. Web缓存
    - 在不访问服务的前提下满足客户端的HTTP请求
    - 原因
        - 缩短客户请求的响应时间
        - 减少机构/组织的流量
        - 在大范围内实现有效的内容分发
    - Web缓存/代理服务器
        - 用户设定浏览器通过缓存进行Web访问
        - 浏览器向缓存/代理服务器发送所有的HTTP请求
        - 缓存既充当客户端，也充当服务器
    - 缓存
        - 客户端
            - get请求
            - If-modified-since:<date>
        - 服务器
            - 没改：304 Not Modified
            - 改变：200 ok <data>