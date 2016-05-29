##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=week_3_oppracht_3
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Dorf\Dropbox\school\Object Oriented Programming In C++\Git\TCTI-V1OOPC-15-BASE"
ProjectPath            := "C:\Users\Dorf\Dropbox\school\Object Oriented Programming In C++\Git\TCTI-V1OOPC-15-BASE\week_3_oppracht_3"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Dorf
Date                   :=29/05/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="week_3_oppracht_3.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  -lgdi32 -static-libgcc -static-libstdc++ 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../Catch/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ball.cpp$(ObjectSuffix) $(IntermediateDirectory)/circle.cpp$(ObjectSuffix) $(IntermediateDirectory)/drawable.cpp$(ObjectSuffix) $(IntermediateDirectory)/filled_rectangle.cpp$(ObjectSuffix) $(IntermediateDirectory)/line.cpp$(ObjectSuffix) $(IntermediateDirectory)/rectangle.cpp$(ObjectSuffix) $(IntermediateDirectory)/vector.cpp$(ObjectSuffix) $(IntermediateDirectory)/victim.cpp$(ObjectSuffix) $(IntermediateDirectory)/wall.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/whelp.cpp$(ObjectSuffix) $(IntermediateDirectory)/window.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/ball.cpp$(ObjectSuffix): ball.cpp $(IntermediateDirectory)/ball.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/ball.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ball.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ball.cpp$(DependSuffix): ball.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ball.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ball.cpp$(DependSuffix) -MM "ball.cpp"

$(IntermediateDirectory)/ball.cpp$(PreprocessSuffix): ball.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ball.cpp$(PreprocessSuffix) "ball.cpp"

$(IntermediateDirectory)/circle.cpp$(ObjectSuffix): circle.cpp $(IntermediateDirectory)/circle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/circle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/circle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/circle.cpp$(DependSuffix): circle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/circle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/circle.cpp$(DependSuffix) -MM "circle.cpp"

$(IntermediateDirectory)/circle.cpp$(PreprocessSuffix): circle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/circle.cpp$(PreprocessSuffix) "circle.cpp"

$(IntermediateDirectory)/drawable.cpp$(ObjectSuffix): drawable.cpp $(IntermediateDirectory)/drawable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/drawable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/drawable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/drawable.cpp$(DependSuffix): drawable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/drawable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/drawable.cpp$(DependSuffix) -MM "drawable.cpp"

$(IntermediateDirectory)/drawable.cpp$(PreprocessSuffix): drawable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/drawable.cpp$(PreprocessSuffix) "drawable.cpp"

$(IntermediateDirectory)/filled_rectangle.cpp$(ObjectSuffix): filled_rectangle.cpp $(IntermediateDirectory)/filled_rectangle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/filled_rectangle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/filled_rectangle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/filled_rectangle.cpp$(DependSuffix): filled_rectangle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/filled_rectangle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/filled_rectangle.cpp$(DependSuffix) -MM "filled_rectangle.cpp"

$(IntermediateDirectory)/filled_rectangle.cpp$(PreprocessSuffix): filled_rectangle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/filled_rectangle.cpp$(PreprocessSuffix) "filled_rectangle.cpp"

$(IntermediateDirectory)/line.cpp$(ObjectSuffix): line.cpp $(IntermediateDirectory)/line.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/line.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/line.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/line.cpp$(DependSuffix): line.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/line.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/line.cpp$(DependSuffix) -MM "line.cpp"

$(IntermediateDirectory)/line.cpp$(PreprocessSuffix): line.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/line.cpp$(PreprocessSuffix) "line.cpp"

$(IntermediateDirectory)/rectangle.cpp$(ObjectSuffix): rectangle.cpp $(IntermediateDirectory)/rectangle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/rectangle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/rectangle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/rectangle.cpp$(DependSuffix): rectangle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/rectangle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/rectangle.cpp$(DependSuffix) -MM "rectangle.cpp"

$(IntermediateDirectory)/rectangle.cpp$(PreprocessSuffix): rectangle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/rectangle.cpp$(PreprocessSuffix) "rectangle.cpp"

$(IntermediateDirectory)/vector.cpp$(ObjectSuffix): vector.cpp $(IntermediateDirectory)/vector.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/vector.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vector.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vector.cpp$(DependSuffix): vector.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vector.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vector.cpp$(DependSuffix) -MM "vector.cpp"

$(IntermediateDirectory)/vector.cpp$(PreprocessSuffix): vector.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vector.cpp$(PreprocessSuffix) "vector.cpp"

$(IntermediateDirectory)/victim.cpp$(ObjectSuffix): victim.cpp $(IntermediateDirectory)/victim.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/victim.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/victim.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/victim.cpp$(DependSuffix): victim.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/victim.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/victim.cpp$(DependSuffix) -MM "victim.cpp"

$(IntermediateDirectory)/victim.cpp$(PreprocessSuffix): victim.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/victim.cpp$(PreprocessSuffix) "victim.cpp"

$(IntermediateDirectory)/wall.cpp$(ObjectSuffix): wall.cpp $(IntermediateDirectory)/wall.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/wall.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wall.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wall.cpp$(DependSuffix): wall.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wall.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wall.cpp$(DependSuffix) -MM "wall.cpp"

$(IntermediateDirectory)/wall.cpp$(PreprocessSuffix): wall.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wall.cpp$(PreprocessSuffix) "wall.cpp"

$(IntermediateDirectory)/whelp.cpp$(ObjectSuffix): whelp.cpp $(IntermediateDirectory)/whelp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/whelp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/whelp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/whelp.cpp$(DependSuffix): whelp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/whelp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/whelp.cpp$(DependSuffix) -MM "whelp.cpp"

$(IntermediateDirectory)/whelp.cpp$(PreprocessSuffix): whelp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/whelp.cpp$(PreprocessSuffix) "whelp.cpp"

$(IntermediateDirectory)/window.cpp$(ObjectSuffix): window.cpp $(IntermediateDirectory)/window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Dorf/Dropbox/school/Object Oriented Programming In C++/Git/TCTI-V1OOPC-15-BASE/week_3_oppracht_3/window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/window.cpp$(DependSuffix): window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/window.cpp$(DependSuffix) -MM "window.cpp"

$(IntermediateDirectory)/window.cpp$(PreprocessSuffix): window.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/window.cpp$(PreprocessSuffix) "window.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


