import java.util.Scanner;
class vowels{
	public static void main(String args){
		String s,op="";
		Scanner sc = new Scanner(System.in);
		s = sc.next();
		for(int i=0;i<s.length();i++){
			if(s.charAt(i)=='a' || s[i]=='e' || s[i]=='i' ||s[i] == 'o' || s[i] == 'u')
				continue;
			else 
				op+=s[i];
		}
		System.out.println(op);
	}
}
