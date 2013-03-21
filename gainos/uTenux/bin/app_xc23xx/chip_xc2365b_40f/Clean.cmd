@echo off
echo "Do you really want to clean all the files copyed by MakeProject.cmd!"
echo "Press any key to do so! Dangerous!"
pause
echo "Start to delete app"
rm -fr ./app
echo "Start to delete config"
rm -fr ./config
echo "Start to delete include"
rm -fr ./include
echo "Start to delete kernel"
rm -fr ./kernel
echo "Start to delete lib"
rm -fr ./lib
echo "Fnished"
pause