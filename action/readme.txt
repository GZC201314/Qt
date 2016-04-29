使用说明
1. 先生成一个动作的文档，格式如下
动作　　　　球员号码　　　时间
strictLead    8   [23, 0]
写文件格式的代码：
    std::ofstream file("action.txt",std::ios::app);
    file<<first_action.description()<<"    "<<wm.self().unum()<<"   "<<wm.seeTime()<<std::endl;
    file.close();
这个小程序是计算一定周期内的带球队员的动作，周期间隔在１００左右

