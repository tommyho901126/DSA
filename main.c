#include <stdio.h>
#include<stdlib.h>
#include "generator.h"
/* 
1.�z�L�Q�ת������F�� (LIAO,CHENG-HUA)
�P���@5��10�� 1:05
�ڭ쥻�]�J��@�˪����D�A��Ӫ����k�OQ��R���n�V�b�@�_sort�A���٬O�n�P�ɶi��]�]�N�O��sort Q�Msort R�g�b�P�@��merge sort�̡^�A�M���intersection���覡�p���� 
�o��ҵo:
����merge sort���L�{���}�l�� 
 �p�G��P�I���Ƨǧ�}�C�ܦ�����A�N�i�H�קK�b�ƥ��I���ɭԡA�ݭn�b����P�I���ɭԡA���s�B�z�w�g�ƧǦn��Q�MR�}�C������T�A���Oarray shift�A�P�ɤ]�i�H�έ���o�쪺��T 
2. ���W���H���Φp�G�C��merge sort �̭���recursion�����@��malloc�|TLE�A���Ӫ����@���ǹL�h�A�b�~���ŧi�@���N�n�A���q��L 
3. �b�O�W�ۤv�ݪ����D�M�U�Ъ��^�H: �p��B�zP�I (�ڷQ�F�ܤ[�~�o�{��Ө���²��A���ӬO�b���ת��ɭԤ@���ѰO�Ҽ{Qmax>Qmid>Rmid�A�ҥH�u�ndescending �N�n�F�A��F�W�[���� 
*/ 
const int de=0;
const int de2=0;
const int de3=0;
const int de4=0;
const int de5=0;
const int de6=0;
const int io=0;

void print_data(int n,int *p,int *q,int *r){
	printf("n:%d",n);
	int i;
	printf("\np:");
	for(i=0;i<n;i++) printf("%d ",p[i]);
	printf("\nq:");
	for(i=0;i<n;i++) printf("%d ",q[i]);
	printf("\nr:");
	for(i=0;i<n;i++) printf("%d ",r[i]);
	printf("\n");
	
}
void merge(int *arr,int *seq,int l0,int lm,int l1,int *temp,int *q){  //write seq->temp
	int ptr1=l0,ptr2=lm+1,ptr3=l0,i;//���F��k�n�O�o��ptr3�_�I�A��F�n�[ 
	if(de5) printf("start merge%d-%d-%d\n",l0,lm,l1);
	if(de5) for(i=l0;i<=lm;i++) printf("%d ",arr[seq[i]]);
	if(de5) printf("\n");
	if(de5) for(i=lm+1;i<=l1;i++) printf("%d ",arr[seq[i]]);
	if(de5) printf("\n");
	if(l1==l0) temp[seq[l1]]=seq[l1];
	else{
		while(ptr1<=lm|ptr2<=l1){
			if(de5) printf("ptr:%d %d %d\n",ptr1,ptr2,ptr3);
			if(ptr1<=lm&ptr2<=l1){
				if(arr[seq[ptr1]]<arr[seq[ptr2]]){
					//if(de5) printf("ptr1 smaller:%d<%d\n",arr[seq[ptr1]],arr[seq[ptr2]]);
					temp[ptr3]=seq[ptr1];
					ptr1=ptr1+1;
				} 
				else if(arr[seq[ptr1]]>arr[seq[ptr2]]){
					//if(de5) printf("ptr1 larger:%d>  ptr2=%d->seq[ptr]=%d->arr=%d\n",arr[seq[ptr1]],ptr2,seq[ptr2],arr[seq[ptr2]]);
					temp[ptr3]=seq[ptr2];
					ptr2=ptr2+1;
				}//P�I�ۦP 
				else if(arr[seq[ptr1]]==arr[seq[ptr2]]){
					if(q[seq[ptr1]]>q[seq[ptr2]]){
						temp[ptr3]=seq[ptr1];
						ptr1=ptr1+1;
					}
					else{
						temp[ptr3]=seq[ptr2];
						ptr2=ptr2+1;
					}
				}
				ptr3=ptr3+1;
			}
			else if(ptr1<=lm){
				while(ptr1<=lm){
					temp[ptr3]=seq[ptr1];
					ptr3=ptr3+1;
					ptr1=ptr1+1;
				}
			}
			else{
				while(ptr2<=l1){
					temp[ptr3]=seq[ptr2];
					ptr2=ptr2+1;
					ptr3=ptr3+1;
				}
			}
			if(de5) for(i=l0;i<lm;i++) printf("(%d,%d)",arr[temp[i]],q[temp[i]]);
			if(de5) printf("\n");
			if(de5) for(i=lm+1;i<=l1;i++) printf("(%d,%d)",arr[temp[i]],q[temp[i]]);
			if(de5) printf("\n");
		}
	}
	
	
	//for(i=0;i<l1-l0+1;i++) seq[l0+i]=temp[i];
	//if(de5) for(i=0;i<l1-l0+1;i++) printf("(%d,%d)",arr[temp[l0+i]],q[seq[l0+i]]);
	//if(de5) printf("\n");
	if(de5) printf("end merging\n\n");
	
}
void merge_sort(int *p,int *seq,int l0,int l1,int *index3,int *q,int x){//seq has information, index is aux
	if(de5) printf("start sorting between %d %d\n",l0,l1);
	int lm=(l0+l1)/2;
	x=x*-1;
	if(l1>l0){
		merge_sort(p,index3,l0,lm,seq,q,x); //seq->index3
		merge_sort(p,index3,lm+1,l1,seq,q,x); //seq->index3
		merge(p,index3,l0,lm,l1,seq,q); //flow: index3->seq
	}
	else if(l1==l0){
		if(x==-1) index3[l1]=seq[l1];//seq->index3
		else seq[l1]=index3[l1];
	}
}

void *merge_qr(int *q,int *r,int *seq,int *seq2,int qr0,int qrm,int qr1,long long *counter,int *temp,int *mark){
	int i,ptr1=qr0,ptr2=qrm+1,ptr3=qr0,k;
	long long j=0;
	//j max=qr1-qrm
	for(i=qr0;i<=qrm;i++){
		if(j<qr1-qrm){
			while(q[seq[i]]>=r[seq2[qrm+1+j]]){
				j=j+1;
				if(j>=qr1-qrm) break;
			} 
		}
		*counter=*counter+j;
		if(de6){
			printf("i=%d:\nq:\n",i);
			for(k=qr0;k<=qrm;k++) printf("%d ",q[seq[k]]);
			printf("\n");
			for(k=qrm+1;k<=qr1;k++) printf("%d ",q[seq[k]]);
			printf("\nr:\n");
			for(k=qr0;k<=qrm;k++) printf("%d ",r[seq[k]]);
			printf("\n");
			for(k=qrm+1;k<=qr1;k++) printf("%d ",r[seq[k]]);
			printf("\ncounter=%lld\n",*counter);
		}
	}
	
	ptr1=qr0,ptr2=qrm+1,ptr3=qr0;
	while(ptr1<=qrm|ptr2<=qr1){
		if(ptr1<=qrm&ptr2<=qr1){
			if(q[seq[ptr1]]<q[seq[ptr2]]){
				temp[ptr3]=seq[ptr1];
				ptr1=ptr1+1;
			} 
			else{
				temp[ptr3]=seq[ptr2];
				ptr2=ptr2+1;
			}
			ptr3=ptr3+1;
		}
		else if(ptr1<=qrm){
			while(ptr1<=qrm){
				temp[ptr3]=seq[ptr1];
				ptr3=ptr3+1;
				ptr1=ptr1+1;
			}
		}
		else{
			while(ptr2<=qr1){
				temp[ptr3]=seq[ptr2];
				ptr2=ptr2+1;
				ptr3=ptr3+1;
			}
		}
		
	}
	//for(i=0;i<qr1-qr0+1;i++) seq[qr0+i]=temp[i];
	
	ptr1=qr0,ptr2=qrm+1,ptr3=qr0;
	while(ptr1<=qrm|ptr2<=qr1){ 
		if(ptr1<=qrm&ptr2<=qr1){
			if(r[seq2[ptr1]]<r[seq2[ptr2]]){
				mark[ptr3]=seq2[ptr1];
				ptr1=ptr1+1;
			} 
			else{
				mark[ptr3]=seq2[ptr2];
				ptr2=ptr2+1;
			}
			ptr3=ptr3+1;
		}
		else if(ptr1<=qrm){
			while(ptr1<=qrm){
				mark[ptr3]=seq2[ptr1];
				ptr3=ptr3+1;
				ptr1=ptr1+1;
			}
		}
		else{
			while(ptr2<=qr1){
				mark[ptr3]=seq2[ptr2];
				ptr2=ptr2+1;
				ptr3=ptr3+1;
			}
		}
		
	}
	//for(i=0;i<qr1-qr0+1;i++) seq2[qr0+i]=temp[i];
}

void merge_sort_qr(int *q,int *r,int *seq,int *seq2,int qr0,int qr1,long long *counter,int *temp,int *mark,int x){
	int qrm=(qr0+qr1)/2;
	x=x*(-1);
	if(qr1>qr0){
		merge_sort_qr(q,r,temp,mark,qr0,qrm,counter,seq,seq2,x);
		merge_sort_qr(q,r,temp,mark,qrm+1,qr1,counter,seq,seq2,x);
		merge_qr(q,r,temp,mark,qr0,qrm,qr1,counter,seq,seq2);
	}
	else if(qr1==qr0){
		if(x==-1) temp[qr1]=seq[qr1];//seq->index3
		else seq[qr1]=temp[qr1];
		if(x==-1) mark[qr1]=seq2[qr1];//seq->index3
		else seq2[qr1]=mark[qr1];
	}
} 

int main() {
	int t;
	if(io) scanf("%d",&t);
	else{
		generator.init();
		t=generator.getT();
	} 
	
	int i,j,k,count,temp;
	long long *counter,c=0;
	counter=&c;
	while (t--) {
		int n, *p, *q, *r,*seq;
		count=0,*counter=0;	
		if(io){
			scanf("%d",&n);
			p=(int *)malloc(sizeof(int)*n);
			q=(int *)malloc(sizeof(int)*n);
			r=(int *)malloc(sizeof(int)*n);
			for(i=0;i<n;i++) scanf("%d",&p[i]);
			for(i=0;i<n;i++) scanf("%d",&q[i]);
			for(i=0;i<n;i++) scanf("%d",&r[i]);
		}
		else generator.getData(&n, &p, &q, &r);
		for(i=0;i<n;i++){
			if(q[i]<r[i]){
				temp=q[i];
				q[i]=r[i];
				r[i]=temp;
			}
		}
		int *mark=(int *)malloc(sizeof(int)*n);
		seq=(int *)malloc(sizeof(int)*n);
		int *index3=(int *)malloc(sizeof(int)*n),*temparr=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++) seq[i]=i;
		
		merge_sort(p,seq,0,n-1,index3,q,1); 
		if(de4) for(i=0;i<n;i++) printf("%d ",p[seq[i]]);
		int *seq2=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++) seq2[i]=seq[i];
		int *seq1=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++) seq1[i]=seq[i];
		
		merge_sort_qr(q,r,seq1,seq2,0,n-1,counter,temparr,mark,1); 
		
		//fix repeat
		int ptrp=0,s=0;
		if(io) printf("\n\n");
		printf("%lld\n",*counter);
		if(io) printf("\n");
	}
	return 0;
}




