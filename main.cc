#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int splitFile(const char* path, int count,  const char* savename)
{
	FILE* F = fopen(path, "rb");
	if (F == NULL)
	{
		return  -1;
	}
	else
	{
		fseek(F, 0, SEEK_END);//将文件指针移动到文件末尾
		int length = ftell(F);//计算文件指针到文件开头的字节数，即就是文件大小
		int yushu = length % count;//余数
		int size = length / count; //前面count-1份每一分大小为size，最后一份为size + yushu
		for (int i = 1; i <= count; i++)
		{
			char savefile[100];
			sprintf(savefile, "%s%d", savename,i);
			printf("%s\n", savefile);
			FILE* P = fopen(savefile, "wb");
			if (P == NULL)
			{
				fclose(F);
				return -1;
			}
			else
			{
				fseek(F, (i - 1) * size, SEEK_SET);
				if (i == count)
				{
					for (int j = 0; j <= size + yushu; j++)
					{
						int c = fgetc(F);
						fputc(c, P);
					}
				}
				else
				{
					for (int j = 0; j < size; j++)
					{
						int c = fgetc(F);
						fputc(c, P);
					}
				}


			}
			fclose(P);
		}
		fclose(F);
		return 0;
	}
}
/*合并文件，合并为一个大文件bigfile返回-1表示分割失败,0表示成功*/
int mergeFile(const char* savename, int count, const char* bigfile)
{

	FILE* BF = fopen(bigfile, "wb");
	if (BF == NULL)
	{
		printf("open file failed");
		return -1;
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			char savefile[100];
			sprintf(savefile, "%s%d",savename,i+1);

			FILE* P = fopen(savefile, "rb");
			if (P == NULL)
			{
				printf("open %s failed", savefile);
				fclose(BF);
				return -1;
			}
			else
			{
				int c = fgetc(P);
				while (c != EOF)
				{
					fputc(c, BF);
					c = fgetc(P);
				}
			}
			fclose(P);
		}
	}
	fclose(BF);
	return 0;
}
int main(int argc, char* argv[])
{
	if (argc < 4) {
		printf("splitmerge.exe split bigfile 10\nsplitmerge.exe merge bigfile 10\n");
		return 0;
	}
	if (strcmp(argv[1], "split") == 0) {

		splitFile(argv[2], atoi(argv[3]), "funnywolf.split");
		printf("split file finish");
		return 0;
	}
	else if (strcmp(argv[1], "merge") == 0) {
		mergeFile("funnywolf.split", atoi(argv[3]), argv[2]);
		printf("merge file finish");
		return 0;
	}
}