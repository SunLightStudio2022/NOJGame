import os
try:
    import pygame
except:
    os.system("pip3 install pygame -i https://pypi.tuna.tsinghua.edu.cn/simple some-package")
    import pygame
screen=0
def pyg_doc(doc):
    global screen
    if doc[0]=="init":
        pygame.init() 
        pygame.display.set_caption(doc[1])
        screen=pygame.display.set_mode((int(doc[2]),int(doc[3])))
    if doc[0]=="display":
        pygame.display.update()
    if doc[0]=="listen":
        return pygame.event.get()
    if doc[0]=="quit":
        pygame.quit()
    if doc[0]=="circle":
        pygame.draw.circle(\
            screen,\
            (int(doc[1]),int(doc[2]),int(doc[3])),\
            (int(doc[4]),int(doc[5])),\
            int(doc[6])\
        )
        pygame.display.update()


    pass
def pyg_cmd(cmd):
    cmd_a=cmd.split(" ")
    cmd_b=[]
    for i in cmd_a:
        if  not i== '' :
            cmd_b.append(i)
    pyg_doc(cmd_b)



#init tile 长 宽         创建
#display                 刷新
#listen                  获取所事件
#quit                    关闭并退出
#cicle  红 黄 蓝 
pyg_cmd("init title 500 500 ")
pyg_cmd("circle 255 0 0 30 40 20")
input()
pyg_cmd("quit")
