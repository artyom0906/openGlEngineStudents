//#include<stdio.h>
//#include<json-c/json.h>
//
//int main(int argc, char **argv) {
//	FILE *fp;
//	char buffer[1024];
//	struct json_object *parsed_json;
//	struct json_object *��������;
//
//	size_t i;	
//
//	fp = fopen("��� �����","r");
//	fread(buffer, 1024, 1, fp);
//	fclose(fp);
//
//	parsed_json = json_tokener_parse(buffer);
//
//	json_object_object_get_ex(parsed_json, "��� � json", &��������);
//
//	printf(json_object_get_string(��������));
//}