# tgrep
Command-line tools for working with meeting notes

## Usage
Usage given by example.  Use `--help` for details.

```
>tgrep --hist
27 files read
192 total todos
100 moved to Todoist
40 cancelled
50 done
2 unresolved
```

Show todos in all files.  Bucket them by user-defined buckets.

```
>tgrep --cat
2 unresolved; 192 total
15-June-25
[ ] Follow-up with Nietzsche - Thursday Standup.txt:line 12
[ ] Eat tacos - bucketlist.txt:line 1
```

Search all files under <path> for any todos, and print them, bucketed

```
>tgrep --launch
```

Launch notepad for the first file with unresolved todos
