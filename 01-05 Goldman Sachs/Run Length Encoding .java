class GfG
 {
	String encode(String str)
	{
          int n = str.length();
          StringBuilder sb = new StringBuilder();
          for(int i = 0; i < n; i++){
              char ch = str.charAt(i);
              sb.append(ch);
              int cnt = 1;
              while((i+1) < n && ch == str.charAt(i+1)){
                  cnt++;
                  i++;
              }
              sb.append(cnt);
          }
          return sb.toString();
	}
 }