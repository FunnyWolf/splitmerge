# 文件分割/合并工具(splitmerge)
splitmerge用于分割/合并文件,当web服务限制上传文件大小时,可通过此工具在本机将文件分割成多个小文件,上传服务器后再次使用该工具将多个小文件合并成一个大文件.
# 使用方法
* 如将cthun.exe分割成3个小文件
```
splitmerge.exe split cthun.exe 3
λ splitmerge.exe split cthun.exe 3
funnywolf.split1
funnywolf.split2
funnywolf.split3
split file finish
F:\splitmerge
λ dir
 驱动器 F 中的卷没有标签。
 卷的序列号是 7825-4014
 F:\splitmerge 的目录
2019/09/27  15:50    <DIR>          .
2019/09/27  15:50    <DIR>          ..
2019/09/11  10:07        23,419,604 cthun.exe
2019/09/27  15:50         7,806,534 funnywolf.split1
2019/09/27  15:50         7,806,534 funnywolf.split2
2019/09/27  15:50         7,806,537 funnywolf.split3
2019/09/27  15:18            17,184 splitmerge
2019/09/27  15:13            10,240 splitmerge.exe
               6 个文件     46,866,633 字节
               2 个目录 981,248,131,072 可用字节
F:\splitmerge
```

* 将funnywolf.split1,funnywolf.split2,funnywolf.split2上传到web服务器后,执行
```
splitmerge.exe merge cthun_new.exe 3
```
将三个文件重新合并成cthun_new.exe

