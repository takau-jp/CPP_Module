./account > output.log
diff -s <(sed 's/^\[[0-9_]*\] //' output.log) <(sed 's/^\[[0-9_]*\] //' tests/19920104_091532.log)