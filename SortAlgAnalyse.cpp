// SortAlgAnalyse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<ctime>
#include<stdlib.h>
#include<algorithm>

//ð������
void BubbleSort(int num,float data[]);
//ѡ������
void SelectSort(int num,float data[]);
//��������
void InsertSort(int num,float data[]);
//���ֲ�������
void BiInsertSort(int num,float data[]);
//��������
void QuickSort(int num,float data[]);
//ϣ������
void ShellSort(int num,float data[]);
//�鲢����
void MergeSort(int num,float data[]);
//������
void HeapSort(int num,float data[]);


int _tmain(int argc, _TCHAR* argv[])
{
	float *data=new float[1000000];
	clock_t time_beg,time_end;

	for(int i=0;i<1000000;++i)
	{
		data[i]=double(rand())/double(RAND_MAX);
	}
	time_beg=clock();
	BubbleSort(1000000,data);
	time_end=clock();
	printf("Bubble Sort time %f ms\n",float(time_end-time_beg));

	for(int i=0;i<1000000;++i)
	{
		data[i]=double(rand())/double(RAND_MAX);
	}
	time_beg=clock();
	SelectSort(100000,data);
	time_end=clock();
	printf("Select Sort time %f ms\n",float(time_end-time_beg));

	for(int i=0;i<1000000;++i)
	{
		data[i]=double(rand())/double(RAND_MAX);
	}
	time_beg=clock();
	InsertSort(1000000,data);
	time_end=clock();
	printf("Insert Sort time %f ms\n",float(time_end-time_beg));

	for(int i=0;i<1000000;++i)
	{
		data[i]=double(rand())/double(RAND_MAX);
	}
	time_beg=clock();
	BiInsertSort(1000000,data);
	time_end=clock();
	printf("Binnary Insert Sort time %f ms\n",float(time_end-time_beg));
	for(int i=0;i<1000000;++i)
	{
		data[i]=double(rand())/double(RAND_MAX);
	}
	time_beg=clock();
	QuickSort(1000000,data);
	time_end=clock();
	printf("Quick Sort time %f ms\n",float(time_end-time_beg));

	for(int i=0;i<1000000;++i)
	{
		data[i]=double(rand())/double(RAND_MAX);
	}
	time_beg=clock();
	ShellSort(1000000,data);
	time_end=clock();
	printf("Shell Sort time %f ms\n",float(time_end-time_beg));

	for(int i=0;i<1000000;++i)
	{
		data[i]=double(rand())/double(RAND_MAX);
	}
	time_beg=clock();
	MergeSort(1000000,data);
	time_end=clock();
	printf("Merge Sort time %f ms\n",float(time_end-time_beg));

	for(int i=0;i<1000000;++i)
	{
		data[i]=double(rand())/double(RAND_MAX);
	}
	time_beg=clock();
	HeapSort(1000000,data);
	time_end=clock();
	printf("Heap Sort time %f ms\n",float(time_end-time_beg));

	delete[]data;
	return 0;
}


void BubbleSort(int num,float data[])
{
	float  temp;  
	printf("Bubble Sort Begin\n");
	for (int i =0;i<=num-1;i++)  
    {  
        for (int j=0;j<=num-i-2;j++)  
        {  
            if (data[j]>data[j+1])  
            {  
                temp=data[j];  
                data[j]=data[j+1];  
                data[j+1]=temp;  
            }  
        } 
    }
	//for(int j=0;j<num;++j)
	//	printf("%f  ",data[j]);
	//printf("\n");
	printf("Bubble Sort End\n");
}
void SelectSort(int num,float data[])
{
	printf("Select Sort Begin\n");
	for(int i=0;i<num;++i)
	{
		float max_value=-99999;
		for(int j=i;j<num;++j)
		{
			max_value=std::max(max_value,data[j]);
		}
		std::swap(max_value,data[i]);
	}
	printf("Select Sort End\n");
}
void InsertSort(int num,float data[])
{
	//����������Ϊǰi-1��Ԫ��������ģ���Ԫ��i���뵽ǰi-1��Ԫ���У�Ȼ��i++
	float temp;
	printf("Insert Sort Begin\n");
	for(int i=1;i<num-1;++i)
	{
		temp=data[i];
		int j=i-1;
		//ȷ�������λ�ò����ƶ�����λ������
		while(temp<data[j])
		{
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=temp;
	}
	//for(int j=0;j<num;++j)
	//	printf("%f  ",data[j]);
	//printf("\n");
	printf("Insert Sort End\n");
}
void BiInsertSort(int num,float data[])
{
	printf("Binnary Insert Sort Begin\n");
	for(int i=1;i<num;i++)
	{
		int left  = 0;
		int right = i-1;
		float temp = 0;

		//ȷ��Ҫ�����λ��
		while(right>=left)
		{
			temp = data[i];
			int mid = (left+right)/2;//�е��λ��
			if(temp>data[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid  -1;
			}
		}
		//��Ҫ������λ��һֱ��������������ֵ�����
		for(int j=i-1;j>right-1;j--)
		{
			data[j+1]=data[j];
		}
		data[right+1]=temp;
	}

	//for(int j=0;j<num;++j)
	//	printf("%f  ",data[j]);
	//printf("\n");
	printf("Binnary Insert Sort End\n");
}
void QuickSort(int left,int right,float data[])
{
	if(left<right)
	{
		float key = data[left];
		int low = left, high = right;
		while(low<high)
		{
			while(low < high && data[high] > key)
			{
				high--;
			}
			if(low < high)
				data[low++]=data[high];
			while(low < high && data[low] < key)
			{
				low++;
			}
			//���ܽ����ˣ���ֵ��Ҫ��λ
			if(low < high)
				data[high--] = data[low];
		}
		data[low] = key;

		QuickSort(left,low-1,data);
		QuickSort(low+1,right,data);
	}
	//printf("Quick Sort End\n");
}
void QuickSort(int num,float data[])
{
	int left=0,right = num-1;
	printf("Quick Sort Begin\n");
	QuickSort(left,right,data);
	//for(int j=0;j<10;++j)
	//	printf("%f  ",data[j]);
	//printf("\n");
	printf("Quick Sort End\n");
}
void ShellSort(int num,float data[])
{
	printf("Shell Sort Begin\n");
	int h=1;
	float temp;
	while(h<num)
	{
		h=3*h+1;
	}
	while(h>0)
	{
		h=h/3;
		for(int i=0;i<h;i++)
		{
			//���в�������
			for(int j=i+h;j<num;j+=h)
			{
				temp=data[j];
				int k=j-h;
				//ȷ�������λ�ò����ƶ�����λ������
				while(k>0&&temp<data[k])
				{
					data[k+h]=data[k];
					k-=h;
				}
				data[k+h]=temp;
			}
		}
	}
	//for(int j=0;j<num;++j)
	//	printf("%f  ",data[j]);
	//printf("\n");
	printf("Shell Sort End\n");
}
void MergeSort(int left,int right,float data[])
{
	int m = (right-left)/2;
	if(m>=1)
	{
		MergeSort(left,m+left,data);
		MergeSort(m+left,right,data);
	}
	else
		return;
	float *b=new float[(m+1)];
	memcpy(b,data+left,sizeof(float)*(m+1));
	int i = 0,j = left+m,k = left;
	while(i<m&&j<right)
	{
		//���ʣ�(һ����������һ�����߼�)
		data[k++] = (data[j] < b[i]) ? data[j++]:b[i++];
	}
	while(i<m)
	{
		data[k++] = b[i++];
	}
	delete[]b;b=NULL;
}
void MergeSort(int num,float data[])
{
	int left=0,right = num;
	printf("Merge Sort Begin\n");
	MergeSort(left,right,data);
	//for(int j=0;j<num;++j)
	//	printf("%f  ",data[j]);
	//printf("\n");
	printf("Merge Sort End\n");
}
void HeapConst(int i,int num,float data[])
{
	//�����ѵĹ���
	int left_child,right_child,max_child;
	left_child = 2*i;
	if(left_child > num)
		return ;
	right_child = left_child + 1;
	max_child = (right_child>num) ? left_child : (data[left_child]>data[right_child]) ? left_child : right_child/*ȡ��Сֵ���±�*/;
	if(data[i]>=data[max_child])//�Ѿ�������õĽ��
		return;
	std::swap(data[i],data[max_child]);
	HeapConst(max_child,num,data);//���ӽڵ��������нڵ���е���������ݹ��õĺã�
}
void HeapSort(int num,float data[])
{
	printf("Heap Sort Begin\n");
	//������
	for(int i=num/2;i>=0;i--)
		HeapConst(i,num,data);

	//Ȼ������ͺ���
	for(int i=1;i<num;++i)
	{
		std::swap(data[0],data[num-i]);
		HeapConst(0,num-i-1,data);
	}

	//for(int j=0;j<num;++j)
	//	printf("%f  ",data[j]);
	//printf("\n");
	printf("Heap Sort End\n");
}