#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//bai code (de 1) theo truong hop ten sinh vien co the trung nhau trong mang

struct Sinhvien{
	int id;
	char name[50];
	char birthday[50];
	char address[50];
	int status;
};
typedef struct Sinhvien SV;

//ham nhap phan tu cua mang
void input(SV *list,int i){
	printf("\nNhap ma sinh vien:");
	scanf("%d",&list[i].id);
	fflush(stdin);
	printf("Nhap ten sinh vien:");
	fgets(list[i].name,50,stdin);
	list[i].name[strlen(list[i].name)-1]='\0';
	printf("Nhap ngay sinh:");
	scanf("%50s",list[i].birthday);
	getchar();
	printf("Nhap dia chi:");
	fgets(list[i].address,50,stdin);
	list[i].address[strlen(list[i].address)-1]='\0';
	printf("Nhap status:");
	scanf("%d",&list[i].status);
}
//ham xuat phan tu cua mang
void print(SV list){
	printf("%10d",list.id);
	printf("%20s",list.name);
	printf("%20s",list.birthday);
	printf("%20s",list.address);
	printf("%10d",list.status);
}
//ham xuat mang
void printN(SV list[],int currentIndex){
	for(int i=0;i<currentIndex;i++){
		print(list[i]);
		printf("\n");
	}}
//ham xoa sinh vien theo ten sinh vien
void deleteSv(int *n,SV list[],char name[]){
	int check=0;
	for(int i=0;i<*n;i++){
		if(strcmp(list[i].name,name)==0){
			check++;
			for(int j=i;j<*n;j++){
				list[j]=list[j+1];
			}
			(*n)--;
			printf("Da thuc hien xoa sinh vien trong danh sach");
		}
	}
	if(check==0){
		printf("Khong tim thay sinh vien can xoa");
	}
}

//ham sap xep sach theo ten sinh vien tang
void incSort(int n,SV list[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(strcmp(list[j].name,list[j+1].name)==1){
				SV tmp=list[j];
				list[j]=list[j+1];
				list[j+1]= tmp;
			}
		}
	}
}
//ham sap xep sach theo ten sinh vien giam
void ascSort(int n,SV list[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(strcmp(list[j].name,list[j+1].name)==-1){
				SV tmp=list[j];
				list[j]=list[j+1];
				list[j+1]= tmp;
			}
		}
	}
}

int main(){
	SV student1={1,"ngoc","20/12/1991","Nam Dinh",0};
	SV student2={2,"manh","1/1/2005","Ha Noi",1};
	SV studentList[1000]={student1,student2};
	int currentIndex=2;
	int choice;
	int subChoice;
	int lookStatus;
	int check;
	char lookName[50];
	int start=0;
	int mid,end;
	do{
		printf("\n1.In toan bo danh sach sinh vien\n");
		printf("2.Them moi sinh vien vao vi tri cuoi cung\n");
		printf("3.Cap nhap thong tin mot sinh vien\n");
		printf("4.Xoa mot sinh vien\n");
		printf("5.Sap xep danh sach\n");
		printf("6.Tim kiem sinh vien theo ten va in ra thong tin\n");
		printf("7.Tim kiem sinh vien theo status va in ra thong tin\n");
		printf("Lua chon cua ban la:");	
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:
				printN(studentList,currentIndex);		
			   break;
			case 2:
				//them moi sinh vien
			  printf("Nhap thong tin them moi sinh vien:");
			  input(studentList,currentIndex);
			  currentIndex++;
			  //in mang moi
			  printN(studentList,currentIndex);
			   break;
			case 3:
			  printf("Nhap ten sinh vien can tim kiem:");
			  check=0;
			  gets(lookName);
			  for(int i=0;i<currentIndex;i++){
			  	if(strcmp(studentList[i].name,lookName)==0){
			  		check++;
			  		printf("Cap nhap thong tin sinh vien co ten la %s:",lookName);
			  		input(studentList,i);
			  		printf("\n");
				  }
			  }
			  if(check==0){
			  	printf("Khong tim thay");
			  }else{
			  	printN(studentList,currentIndex);
			  }
			  //in mang sau khi cap nhap thong tin sinh vien			  
			   break;
			case 4:
              printf("Nhap ten sinh vien can xoa:");
			  gets(lookName);
			  deleteSv(&currentIndex,studentList,lookName);
			  //in mang sau khi xoa sinh vien
			  printf("\n");
			  printN(studentList,currentIndex);
			   break;
			case 5:
				printf("\n1. Sap xep danh sach theo ten tang dan\n");
				printf("2. Sap xep danh sach theo ten giam dan\n");
				printf("Lua chon cua ban la:");
				scanf("%d",&subChoice);
				getchar();
				if(subChoice==1){
					incSort(currentIndex,studentList);					
					printf("Danh sach sau khi sap xep tang dan theo ten sinh vien");
					printf("\n");
					printN(studentList,currentIndex);
				}else if(subChoice==2){
					ascSort(currentIndex,studentList);
					printf("Danh sach sau khi sap xep giam dan theo ten sinh vien");
					printf("\n");
					printN(studentList,currentIndex);
				} else{
					printf("Lua chon 1 hoac 2");
				}
				break;
			case 6:
         	    printf("Nhap ten sinh vien can tim kiem:");
			    gets(lookName);			 
			    end=currentIndex;
			    check=0;
			    //sap xep danh sach tang dan theo ten
			    incSort(currentIndex,studentList);
			    //tim kiem nhi ph
			    while (start<=end){
			    	mid=(start+end)/2;
			    	if(strcmp(studentList[mid].name,lookName)==0){
			    		check++;
			    		break;
					}else if(strcmp(studentList[mid].name,lookName)==-1){
						start=mid+1;
					}else{
						end=mid-1;
					}
				}
				if(check==0){
					printf("Khong tim thay");
				}else{
					printf("\nThong tin sinh vien can tim kiem la:\n");
					print(studentList[mid]);
				}
				break;
			case 7:
				check=0;
			    printf("Nhap status sinh vien can tim kiem:");
			    scanf("%d",&lookStatus);			 
			    for(int i=0;i<currentIndex;i++){
			  	if(studentList[i].status==lookStatus){
			  		check++;
			  		printf("Thong tin sinh vien co status la %d:\n",lookStatus);
			  		print(studentList[i]);
			  		printf("\n");
				  }
			    }
			    if(check==0){
			    	printf("Khong tim thay");
				}
				break;
			default:
			   printf("Lua chon tu 1 den 7");	
		}
	}while(1==1);
}
