# Dot-source the conanrun script to set environment, then export selected vars to a .env file
param(
    [string]$OutFile
)
Set-StrictMode -Off

& 'build\generators\conanrun.ps1'

Write-Output "Running conanrun.ps1 to set environment..."
. "$(Join-Path $PSScriptRoot '..\build\generators\conanrun.ps1')"
Write-Output "Exporting env vars to $OutFile"
Get-ChildItem Env: | Where-Object { $_.Name -in @('Path', 'QT_PLUGIN_PATH') } | ForEach-Object {
    "$($_.Name)=$($_.Value)"
} | Out-File -Encoding UTF8 -FilePath $OutFile
Write-Output "Export complete."
