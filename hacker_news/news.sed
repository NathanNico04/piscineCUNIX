/class="titlelink"/{
s/.*href="\([^"]*\)"[^>]*class="titlelink"[^>]*>\([^<]*\)<.*/**\2**\
\1\
/
p
}
