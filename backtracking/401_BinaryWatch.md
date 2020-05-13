# 描述
二进制手表
二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。

每个 LED 代表一个 0 或 1，最低位在右侧。
例如，上面的二进制手表读取 “3:25”。

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

>案例:
输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 

注意事项:
输出的顺序没有要求。
小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-watch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# 分析
明显感觉到就是回溯的思想，但是一些注意事项加了一些难度。
```
backtrack:
  判断条件-->亮灯数等于要求，则添加合法字符串
  列举所有选项-->小时和分钟共10种可选的位置，但是已经亮了的不能重复亮，从k开始
  判断是否合法-->小时0-11，分钟0-59
  更新状态 -->该选项位置的灯从暗变亮
  step forward --> 开始位置 亮灯数 已经亮的灯
  恢复状态
 ```
 整体框架仍是如此，但是怎么把二进制的灯表示为要求的字符串是有技巧的。
 可以用大小为10的数组，初始全是0，对应位置的灯亮变为1.既可以标明哪个位置的灯亮，又可以统一的处理小时和分钟。
 用单独的函数来解析，可以直接解析这个数组，来判断小时分钟是否合法，以及转换成字符串。
 
 # Code
 ```cpp
 class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string>ans;
        string temp;
        vector<bool>visit;
        for(int i = 0;i<10;i++)
        visit.push_back(false);
        backtrack(0,0,num,ans,visit);
        return ans;
    }
    //判断数字合法
    bool isvalidtime(vector<bool>visit){
        bool ans;
        int h=0,m=0;
        int led[] = {1,2,4,8,1,2,4,8,16,32};
        for(int i = 0;i<10;i++){
            if(visit[i]){
                if(i<4)
                    h+=led[i];
                else
                    m+=led[i];
            }
        }
        return  h>=0 && h<=11 && m>=0 && m<=59;
    }
    //visit 01数组按要求转成字符串
    string handletime(vector<bool>visit){
        int h=0,m=0;
        int led[] = {1,2,4,8,1,2,4,8,16,32};
        for(int i = 0;i<10;i++){
            if(visit[i]){
                if(i<4)
                    h+=led[i];
                else
                    m+=led[i];
            }
        }
        string ans  = "";
        if(h==10){
            ans = ans + "10";
        }
        else if (h == 11){
            ans = ans + "11";
        }
        else  ans += (h+'0');
        ans +=":";
        string minu = "";
        if(m<10){
            minu +="0";
            minu += to_string(m);
        }
        else{
            int t = m/10;
            minu += (t%10+'0');
            minu += (m%10+'0');
        }
        ans += minu;
        return ans;
    }
    void backtrack(int step,int k,int num, vector<string>&ans,vector<bool>&visit){
        if(step==num){
            string temp = handletime(visit);
            ans.push_back(temp);
        }
        for(int i = k;i<10;i++){
            visit[i]=1;
            if(isvalidtime(visit)){
                visit[i]=1;
                backtrack(step+1,i+1,num,ans,visit);
                visit[i]=0;
            }
            visit[i]=0;
            
        }
    }
};
 ```

