
set(1)
voor tijd
set(0)

bool measurement = true
bool echohasbeen = false

while(measurement){
	if (echo.get())
	{
		eerste timestamp = timestamp;
		echohasbeen = true
	}

	if (!echo.get() && echohasbeen)
	{
		tweede timestamp = timestamp;
		measurement = false;
	}
}