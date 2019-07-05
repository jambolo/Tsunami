# Microsoft Developer Studio Project File - Name="Tsunami" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Tsunami - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Tsunami.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Tsunami.mak" CFG="Tsunami - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Tsunami - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Tsunami - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/Tsunami", IFBAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Tsunami - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 winmm.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Tsunami - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /Gi /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /map

!ENDIF 

# Begin Target

# Name "Tsunami - Win32 Release"
# Name "Tsunami - Win32 Debug"
# Begin Group "HumanPlayer Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\HumanPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\HumanPlayer.h
# End Source File
# Begin Source File

SOURCE=.\YourTurnDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\YourTurnDialog.h
# End Source File
# End Group
# Begin Group "ComputerPlayer Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ComputerPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputerPlayer.h
# End Source File
# Begin Source File

SOURCE=.\GameTree.cpp
# End Source File
# Begin Source File

SOURCE=.\GameTree.h
# End Source File
# End Group
# Begin Group "Interface"

# PROP Default_Filter ""
# Begin Group "MFC Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\AboutDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\AboutDialog.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\NewGameDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\NewGameDialog.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Tsunami.cpp
# End Source File
# Begin Source File

SOURCE=.\Tsunami.h
# End Source File
# Begin Source File

SOURCE=.\Tsunami.rc
# End Source File
# Begin Source File

SOURCE=.\TsunamiDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\TsunamiDoc.h
# End Source File
# Begin Source File

SOURCE=.\TsunamiView.cpp
# End Source File
# Begin Source File

SOURCE=.\TsunamiView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Tsunami.ico
# End Source File
# Begin Source File

SOURCE=.\res\Tsunami.rc2
# End Source File
# Begin Source File

SOURCE=.\res\TsunamiDoc.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\GameRecordEntry.cpp
# End Source File
# Begin Source File

SOURCE=.\GameRecordEntry.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Board.cpp
# End Source File
# Begin Source File

SOURCE=.\Board.h
# End Source File
# Begin Source File

SOURCE=.\CompressedBoard.h
# End Source File
# Begin Source File

SOURCE=.\GameState.cpp
# End Source File
# Begin Source File

SOURCE=.\GameState.h
# End Source File
# Begin Source File

SOURCE=.\GoTypes.h
# End Source File
# Begin Source File

SOURCE=.\Move.cpp
# End Source File
# Begin Source File

SOURCE=.\Move.h
# End Source File
# Begin Source File

SOURCE=.\Player.cpp
# End Source File
# Begin Source File

SOURCE=.\Player.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\ZHash.cpp
# End Source File
# Begin Source File

SOURCE=.\ZHash.h
# End Source File
# End Target
# End Project
