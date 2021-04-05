# GET POS

This software helps to get position of searched data for in_tail fluentd plugin

pos_file file [contants](https://github.com/fluent/fluentd/blob/5ed4b29ebda0815edb7bdd444e7e5ca2e9874a27/lib/fluent/plugin/in_tail.rb#L667):

```
logFileName                 position            inode
/var/log/nginx/access.log	0000000049599227	00000000022804c7
```


Build: 
```sh
gcc -o getpos getpos.c
```

Usage:
```sh
./getpos "Text to search" /path/to/file <max-count>
<max-count> - occurrences counter
```

Example:
```sh
./getpos "05/Apr/2021:19:31:03" /var/log/nginx/access.log 
Trying find this text "05/Apr/2021:19:31:03" position in file: "/var/log/nginx/access.log"

Line #8: 1.1.1.1 - - [05/Apr/2021:19:31:03 +0300] "GET /admin//config.php HTTP/1.1" 404 2122 "-" "curl/7.15.5 (x86_64-redhat-linux-gnu) libcurl/7.15.5 OpenSSL/0.9.8b zlib/1.2.3 libidn/0.6.5"
HEX ADDRESS: 00000000000004b9
```

