//
递归 General

问题的传递
不停地缩小问题规模

Iteration: bottom-up
Recursion: top-down

run-time stack  先进后出

记忆化: 将已经执行过的结果存储, 大大降低时间复杂度

可以用循环写的都可以用递归写, 但是没必要
***当问题与子问题相似时, 最适合用递归
***当数据结构是递归型时(如: 文件夹里套着文件夹里套着文件夹里套着...)
//
分治: 每个小问题都与大问题相同/相似

广度优先搜索 (bfs): 最短路径, 所有路线同时进行, 一旦一条达到终点就停止
    queue<数据类型>q: push( )/pop() 推出最前面的数值/front()/empty() 是空true,非空false
    对整张图遍历
模板:
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

深度优先搜索 (dfs): 一次一条找 (迷宫)      ***主要思想: 找邻居节点
            回溯(所有邻居节点跑完后, 重置这个节点的状态)/剪枝(避免重复, visited)
            dfs的作用只是找路线, 其他操作最好不要在dfs里面进行

vector
v.push_back(element);   O(1)
v.size();
//
Binary search:
    要很快确定一个值是否可行
    数据单调性
    肯定能用枚举做出来
    一半满足一个条件, 另一半不满足
模板:
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
前缀和: 求subset和
一维数组pre-fix: p[i]=p[i-1]+a[i];
二维数组pre-fix: p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];

差分数组
一段segment做相同加减操作
还原: 对差分数组求前缀和
一维数组: d[i]=a[i]-a[i-1];
[a,b]增加n: a位+n,(b+1)位-n
二维数组: d[i][j]=a[i-1][j-1]+a[i][j]-a[i-1][j]-a[i][j-1];
[i][j]--[x][y]增加k:
    d[i][j]+=k;
    d[x+1][y+1]+=k;
    d[i][y+1]-=k;
    d[x+1][j]-=k;
//
图论:
    无向
    有向: vector  O(V+E)  v:verticle, e:edge/邻接矩阵  O(V^2)     保存邻居
//
ST表: 分治
max[i][j]  从i开始长度为2^j的子区间的最大值
min[i][j]  ...                       最小值

for(int i=1;i<=n;i++){
    cin>>h[i];
    mn[i][0]=mx[i][0]=h[i];
}
for(int k=1;(1<<k)<=n;k++){  // 1<<k: 2^k (左移操作) 1: 原数字  k:左移k位 (每移一位 *2; *2^k)
    for(int i=1;i+(1<<k)-1<=n;i++){
        mn[i][k]=min(mn[i][k-1],mn[i+(1<<k-1)][k-1]);

    }
}
//
01背包:
两个变量矛盾, 列出所有情况
f[i][j]=max(f[i-1][j-w[i]]+v[i], f[i-1][j]);
//
快速幂:
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
取模:
求最大公约数
int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

模运算:
(a+b)%p=(a%p+b%p)%p
(a^b)%p=((a%p)^b)%p
除了除法, 其他加减乘都可以用以上方式
基本与四则运算相同, 整体最后再取模一次
除法(/b)当乘法(*1/b)
或 费马小定理: a^(p-2)=1/a(mod p)
a/b%p=a*b^(p-2)%p
用快速幂算b^(p-2)
//
list链表: 插入删除fast, 访问slow
data+pointer
//
迭代器 (用于vector,array等等, stack,queue不能用)
auto it=v1.begin();
auto it=v1.end()-1;
auto自动识别数据类型
it是地址
e.g:
vector <int> v1={1,2,3,4,5};
for(vector<int>::iterator(或auto) it=v1.begin(); it!=v1.end();it++){
    *it +=10;
}
for(vector<int>::iterator(或auto) it=v1.rbegin(); it!=v1.rend();it++){
    cout<<*it;
}
用struct会有不同:
struct point{
    int x;
    int y;
};
vector <point> v2;
v2.push_back((point){2,3});
for(vector<point>::iterator(或auto) it=v1.rbegin(); it!=v1.rend();it++){
    cout<< it->x << " "<< it->y <<endl;
}
//
pair: c++自带的structor
vector<pair<int,string>>v;
v.push_back(make_pair(19,"aaa"));
v.emplace_back(19,"aaa");
sort(v,v+n) //自动按first,second顺序排列
//
vector <int> v={1,2,3,4,5};
auto a=v.upper_bound(3); >3
auto b=v.lower_bound(3); >=3
cout<<*a<<*b<<endl;
//
set
set特点:
    1)迭代器只能自增自减 (*it++)
    2)自动排序, 不重复
逻辑: AVL树, 红黑树 --> 平衡二叉树
set <A> B;
B.insert(x)
B.count(x)  返回1/0 (set可以自动去重)
B.find(x) 返回迭代器, 如果找不到输出end(比最后一位多1)
以上方法时间复杂度皆为logN
for(auto i:B)
construct:
int num[]={1,2,2,3,4};
set<int> s1(num,num+5);
set<int> s2(s1);
set<int> s3({1,2,2,3,4});
排序:
bool cmp(int a,int b){
    return a>b;
}
set<int,decltype(&cmp)> s(cmp);

//
map
强调对应关系
map<string,int>m1;
m1={...};
迭代器:
    cout<< it->first << " "<< it->second <<endl; //first为key, second为value
