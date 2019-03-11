void add_ldpllib(compiler_state & state){
state.add_var_code("#include <math.h>");
state.add_var_code("#include <iostream>");
state.add_var_code("#include <string>");
state.add_var_code("#include <limits>");
state.add_var_code("#include <limits.h>");
state.add_var_code("#include <map>");
state.add_var_code("#include <stdlib.h>");
state.add_var_code("");
state.add_var_code("#define NVM_FLOAT_EPSILON 0.00000001");
state.add_var_code("#define ldpl_number long double");
state.add_var_code("");
state.add_var_code("using namespace std;");
state.add_var_code("");
state.add_var_code("struct ldpl_num_vector{");
state.add_var_code("map<string, ldpl_number> inner_map;");
state.add_var_code("ldpl_number operator [] (string & i) const {");
state.add_var_code("return inner_map.at(i);");
state.add_var_code("}");
state.add_var_code("ldpl_number& operator [] (string & i) {");
state.add_var_code("return inner_map[i];");
state.add_var_code("}");
state.add_var_code("ldpl_number operator [] (ldpl_number i) const {");
state.add_var_code("return inner_map.at(to_string(i));");
state.add_var_code("}");
state.add_var_code("ldpl_number& operator [] (ldpl_number i) {");
state.add_var_code("return inner_map[to_string(i)];");
state.add_var_code("}");
state.add_var_code("};");
state.add_var_code("");
state.add_var_code("struct ldpl_str_vector{");
state.add_var_code("map<string, string> inner_map;");
state.add_var_code("string operator [] (string & i) const {");
state.add_var_code("return inner_map.at(i);");
state.add_var_code("}");
state.add_var_code("string& operator [] (string & i) {");
state.add_var_code("return inner_map[i];");
state.add_var_code("}");
state.add_var_code("string operator [] (ldpl_number i) const {");
state.add_var_code("return inner_map.at(to_string(i));");
state.add_var_code("}");
state.add_var_code("string& operator [] (ldpl_number i) {");
state.add_var_code("return inner_map[to_string(i)];");
state.add_var_code("}");
state.add_var_code("};");
state.add_var_code("");
state.add_var_code("ldpl_number input_number(){");
state.add_var_code("string s = \"\";");
state.add_var_code("while(true){");
state.add_var_code("getline(cin, s);");
state.add_var_code("try {");
state.add_var_code("ldpl_number num = stod(s);");
state.add_var_code("return num;");
state.add_var_code("}");
state.add_var_code("catch (const std::invalid_argument& ia) {");
state.add_var_code("cout << \"Redo from start: \" << flush;");
state.add_var_code("}");
state.add_var_code("}");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("string input_string(){");
state.add_var_code("string s = \"\";");
state.add_var_code("getline(cin, s);");
state.add_var_code("return s;");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("string input_until_eof(){");
state.add_var_code("stringstream full;");
state.add_var_code("string s;");
state.add_var_code("bool firstLine = true;");
state.add_var_code("while (getline(cin, s)) {");
state.add_var_code("if(!firstLine) s = \"\n\" + s;");
state.add_var_code("firstLine = false;");
state.add_var_code("full << s;");
state.add_var_code("}");
state.add_var_code("return full.str();");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("bool num_equal(ldpl_number a, ldpl_number b){");
state.add_var_code("return fabs(a - b) < NVM_FLOAT_EPSILON;");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("ldpl_number modulo(ldpl_number a, ldpl_number b){");
state.add_var_code("return (int) floor(a) % (int) floor(b);");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("void join(const string & a, const string & b, string & c){");
state.add_var_code("c = a + b;");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("//http://www.zedwood.com/article/cpp-utf8-strlen-function");
state.add_var_code("int utf8_strlen(const string& str)");
state.add_var_code("{");
state.add_var_code("int c,i,ix,q;");
state.add_var_code("for (q=0, i=0, ix=str.length(); i < ix; i++, q++)");
state.add_var_code("{");
state.add_var_code("c = (unsigned char) str[i];");
state.add_var_code("if      (c>=0   && c<=127) i+=0;");
state.add_var_code("else if ((c & 0xE0) == 0xC0) i+=1;");
state.add_var_code("else if ((c & 0xF0) == 0xE0) i+=2;");
state.add_var_code("else if ((c & 0xF8) == 0xF0) i+=3;");
state.add_var_code("else return 0;");
state.add_var_code("}");
state.add_var_code("return q;");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("//http://www.zedwood.com/article/cpp-utf-8-mb_substr-function");
state.add_var_code("string utf8_substr(const string &str,int start, int length=INT_MAX)");
state.add_var_code("{");
state.add_var_code("int i,ix,j,realstart,reallength;");
state.add_var_code("if (length==0) return \"\";");
state.add_var_code("if (start<0 || length <0)");
state.add_var_code("{");
state.add_var_code("//find j=utf8_strlen(str);");
state.add_var_code("for(j=0,i=0,ix=str.length(); i<ix; i+=1, j++)");
state.add_var_code("{");
state.add_var_code("unsigned char c= str[i];");
state.add_var_code("if      (c>=0   && c<=127) i+=0;");
state.add_var_code("else if (c>=192 && c<=223) i+=1;");
state.add_var_code("else if (c>=224 && c<=239) i+=2;");
state.add_var_code("else if (c>=240 && c<=247) i+=3;");
state.add_var_code("else if (c>=248 && c<=255) return \"\";//invalid utf8");
state.add_var_code("}");
state.add_var_code("if (length !=INT_MAX && j+length-start<=0) return \"\";");
state.add_var_code("if (start  < 0 ) start+=j;");
state.add_var_code("if (length < 0 ) length=j+length-start;");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("j=0,realstart=0,reallength=0;");
state.add_var_code("for(i=0,ix=str.length(); i<ix; i+=1, j++)");
state.add_var_code("{");
state.add_var_code("if (j==start) { realstart=i; }");
state.add_var_code("if (j>=start && (length==INT_MAX || j<=start+length)) { reallength=i-realstart; }");
state.add_var_code("unsigned char c= str[i];");
state.add_var_code("if      (c>=0   && c<=127) i+=0;");
state.add_var_code("else if (c>=192 && c<=223) i+=1;");
state.add_var_code("else if (c>=224 && c<=239) i+=2;");
state.add_var_code("else if (c>=240 && c<=247) i+=3;");
state.add_var_code("else if (c>=248 && c<=255) return \"\";//invalid utf8");
state.add_var_code("}");
state.add_var_code("if (j==start) { realstart=i; }");
state.add_var_code("if (j>=start && (length==INT_MAX || j<=start+length)) { reallength=i-realstart; }");
state.add_var_code("");
state.add_var_code("return str.substr(realstart,reallength);");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("ldpl_number str_len(string & a){");
state.add_var_code("return utf8_strlen(a);");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("ldpl_number get_char_num(string & chr){");
state.add_var_code("if (chr.size() != 1) {");
state.add_var_code("cerr << \"\033[1;31mError: GET CHAR AT expects a string of length 1, got: \033[1;37m\";");
state.add_var_code("cerr << chr << endl;");
state.add_var_code("cerr << \"\033[0m\" << endl;");
state.add_var_code("exit(1);");
state.add_var_code("}");
state.add_var_code("int ord = chr[0];");
state.add_var_code("return ord;");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("string charat(string & s, ldpl_number & pos){");
state.add_var_code("unsigned int _pos = floor(pos);");
state.add_var_code("return utf8_substr(s, pos, 1);");
state.add_var_code("}");
state.add_var_code("");
state.add_var_code("#include <cstdio>");
state.add_var_code("#include <memory>");
state.add_var_code("#include <stdexcept>");
state.add_var_code("#include <string>");
state.add_var_code("#include <array>");
state.add_var_code("");
state.add_var_code("string exec(const char* cmd) {");
state.add_var_code("array<char, 128> buffer;");
state.add_var_code("string result;");
state.add_var_code("unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, \"r\"), pclose);");
state.add_var_code("if (!pipe) {");
state.add_var_code("throw runtime_error(\"popen() failed!\");");
state.add_var_code("}");
state.add_var_code("while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {");
state.add_var_code("result += buffer.data();");
state.add_var_code("}");
state.add_var_code("return result;");
state.add_var_code("}");
state.add_var_code("");
}