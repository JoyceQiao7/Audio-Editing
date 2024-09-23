//
�ݹ� General

����Ĵ���
��ͣ����С�����ģ

Iteration: bottom-up
Recursion: top-down

run-time stack  �Ƚ����

���仯: ���Ѿ�ִ�й��Ľ���洢, ��󽵵�ʱ�临�Ӷ�

������ѭ��д�Ķ������õݹ�д, ����û��Ҫ
***������������������ʱ, ���ʺ��õݹ�
***�����ݽṹ�ǵݹ���ʱ(��: �ļ����������ļ����������ļ���������...)
//
����: ÿ��С���ⶼ���������ͬ/����

����������� (bfs): ���·��, ����·��ͬʱ����, һ��һ���ﵽ�յ��ֹͣ
    queue<��������>q: push( )/pop() �Ƴ���ǰ�����ֵ/front()/empty() �ǿ�true,�ǿ�false
    ������ͼ����
ģ��:
    void bfs(point start){
        vis[start.r][start.c]=1;
        q.push(start);
        while(!q.empty()){
            point first=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                point next;
                next.r=first.r+dr[i];
                next.c=first.c+dc[i];
                if(check(next)&&vis[next.r][next.c]==0&&grid[next.r][next.c]==0){
                    grid[next.r][next.c]=2;
                    q.push(next);
                    vis[next.r][next.c]=1;
                }
            }
        }
    }

����������� (dfs): һ��һ���� (�Թ�)      ***��Ҫ˼��: ���ھӽڵ�
            ����(�����ھӽڵ������, ��������ڵ��״̬)/��֦(�����ظ�, visited)
            dfs������ֻ����·��, ����������ò�Ҫ��dfs�������

vector
v.push_back(element);   O(1)
v.size();
//
Binary search:
    Ҫ�ܿ�ȷ��һ��ֵ�Ƿ����
    ���ݵ�����
    �϶�����ö��������
    һ������һ������, ��һ�벻����
ģ��:
    int binarySearch(int num){
        int l=-1,r=n;
        while(l+1!=r){
            int m=(l+r)/2;
            if(arr[m]<arr[num]+c){
                l=m;
            }
            else{
                r=m;
            }
        }
        return l;
    }

//
ǰ׺��: ��subset��
һά����pre-fix: p[i]=p[i-1]+a[i];
��ά����pre-fix: p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];

�������
һ��segment����ͬ�Ӽ�����
��ԭ: �Բ��������ǰ׺��
һά����: d[i]=a[i]-a[i-1];
[a,b]����n: aλ+n,(b+1)λ-n
��ά����: d[i][j]=a[i-1][j-1]+a[i][j]-a[i-1][j]-a[i][j-1];
[i][j]--[x][y]����k:
    d[i][j]+=k;
    d[x+1][y+1]+=k;
    d[i][y+1]-=k;
    d[x+1][j]-=k;
//
ͼ��:
    ����
    ����: vector  O(V+E)  v:verticle, e:edge/�ڽӾ���  O(V^2)     �����ھ�
//
ST��: ����
max[i][j]  ��i��ʼ����Ϊ2^j������������ֵ
min[i][j]  ...                       ��Сֵ

for(int i=1;i<=n;i++){
    cin>>h[i];
    mn[i][0]=mx[i][0]=h[i];
}
for(int k=1;(1<<k)<=n;k++){  // 1<<k: 2^k (���Ʋ���) 1: ԭ����  k:����kλ (ÿ��һλ *2; *2^k)
    for(int i=1;i+(1<<k)-1<=n;i++){
        mn[i][k]=min(mn[i][k-1],mn[i+(1<<k-1)][k-1]);

    }
}
//
01����:
��������ì��, �г��������
f[i][j]=max(f[i-1][j-w[i]]+v[i], f[i-1][j]);
//
������:
n^k=(n^k/2)^2

long long power(long long n, long long k){
    if(k==0){
        return 1;
    }
    long long res=power(n,k/2);
    if(k%2==1){
        return res*res*n;
    }
    return res*res;
}
//
ȡģ:
�����Լ��
int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

ģ����:
(a+b)%p=(a%p+b%p)%p
(a^b)%p=((a%p)^b)%p
���˳���, �����Ӽ��˶����������Ϸ�ʽ
����������������ͬ, ���������ȡģһ��
����(/b)���˷�(*1/b)
�� ����С����: a^(p-2)=1/a(mod p)
a/b%p=a*b^(p-2)%p
�ÿ�������b^(p-2)
//
list����: ����ɾ��fast, ����slow
data+pointer
//
������ (����vector,array�ȵ�, stack,queue������)
auto it=v1.begin();
auto it=v1.end()-1;
auto�Զ�ʶ����������
it�ǵ�ַ
e.g:
vector <int> v1={1,2,3,4,5};
for(vector<int>::iterator(��auto) it=v1.begin(); it!=v1.end();it++){
    *it +=10;
}
for(vector<int>::iterator(��auto) it=v1.rbegin(); it!=v1.rend();it++){
    cout<<*it;
}
��struct���в�ͬ:
struct point{
    int x;
    int y;
};
vector <point> v2;
v2.push_back((point){2,3});
for(vector<point>::iterator(��auto) it=v1.rbegin(); it!=v1.rend();it++){
    cout<< it->x << " "<< it->y <<endl;
}
//
pair: c++�Դ���structor
vector<pair<int,string>>v;
v.push_back(make_pair(19,"aaa"));
v.emplace_back(19,"aaa");
sort(v,v+n) //�Զ���first,second˳������
//
vector <int> v={1,2,3,4,5};
auto a=v.upper_bound(3); >3
auto b=v.lower_bound(3); >=3
cout<<*a<<*b<<endl;
//
set
set�ص�:
    1)������ֻ�������Լ� (*it++)
    2)�Զ�����, ���ظ�
�߼�: AVL��, ����� --> ƽ�������
set <A> B;
B.insert(x)
B.count(x)  ����1/0 (set�����Զ�ȥ��)
B.find(x) ���ص�����, ����Ҳ������end(�����һλ��1)
���Ϸ���ʱ�临�ӶȽ�ΪlogN
for(auto i:B)
construct:
int num[]={1,2,2,3,4};
set<int> s1(num,num+5);
set<int> s2(s1);
set<int> s3({1,2,2,3,4});
����:
bool cmp(int a,int b){
    return a>b;
}
set<int,decltype(&cmp)> s(cmp);

//
map
ǿ����Ӧ��ϵ
map<string,int>m1;
m1={...};
������:
    cout<< it->first << " "<< it->second <<endl; //firstΪkey, secondΪvalue
