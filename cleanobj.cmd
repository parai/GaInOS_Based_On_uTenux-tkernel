@echo off
echo "Remove Object Files"
gfind ./ -name "*.[oa]" |xargs -i echo 'rm' {}
gfind ./ -name "*.[oa]" |xargs -i rm {}
gfind ./ -name "*.pyc" |xargs -i echo 'rm' {}
gfind ./ -name "*.pyc" |xargs -i rm {}
gfind ./ -name "*.abs" |xargs -i echo 'rm' {}
gfind ./ -name "*.abs" |xargs -i rm {}
gfind ./ -name "*.bak" |xargs -i echo 'rm' {}
gfind ./ -name "*.bak" |xargs -i rm {}
pause