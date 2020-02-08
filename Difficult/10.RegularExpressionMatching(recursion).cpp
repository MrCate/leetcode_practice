bool isMatch2(string s, string p) {
        return helperMatch(s, p, 0, 0);
    }

    bool helperMatch(string &s, string &p, int i, int j){
        int ns = s.size();
        int np = p.size();
        if(np == j){
            if(ns == i) return true;
            return false;
        }
        bool one = false, zero = false;
        if(j + 1 < np && p[j+1] == '*'){  // 遇到*时
            zero = helperMatch(s, p, i, j+2);  // 使用0次
            if(!zero && (i < ns) && (p[j] == s[i] || p[j] == '.')){
                one = helperMatch(s, p, i+1, j);  // 使用多次
            }
            return zero || one;
        }else{
            if((i < ns) && (p[j] == s[i] || p[j] == '.')){
                return helperMatch(s, p, i+1, j+1);  // 当前字符正常匹配
            }else{
                return false;  // 不匹配
            }
        }
        return false;
    }
};