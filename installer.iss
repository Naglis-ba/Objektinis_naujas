[Setup]
AppName=Objektinis
AppVersion=1.0
DefaultDirName={pf}\VU\Naglis-Baranauskas
DefaultGroupName=VU\Naglis-Baranauskas
OutputBaseFilename=Naglis-Baranauskas-Setup
Compression=lzma
SolidCompression=yes
WizardStyle=modern
PrivilegesRequired=admin


[Files]
Source: "out\build\x64-Release\Objektinis.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "out\build\x64-Release\*.txt"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
; Start Menu nuoroda
Name: "{group}\Naglis-Baranauskas"; Filename: "{app}\Objektinis.exe"

; Desktop nuoroda
Name: "{commondesktop}\Naglis-Baranauskas"; Filename: "{app}\Objektinis.exe"


[Run]
Filename: "{app}\Objektinis.exe"; Description: "Run Objektinis"; Flags: nowait postinstall skipifsilent runasoriginaluser
