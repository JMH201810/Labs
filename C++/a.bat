for /d %%i in (scratc*) do (
cd "%%i"
move _cproject.xml .cproject
move _project.xml .project
cd ..
)