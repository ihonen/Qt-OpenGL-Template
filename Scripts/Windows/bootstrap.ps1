Set-Variable -Name "GL3W_DIR" -Value "$PSScriptRoot\..\Extern\gl3w"
python3 "$GL3W_DIR\gl3w_gen.py" --root="$GL3W_DIR\gen"
