# This is the default standard .cshrc provided to csh users.
# They are expected to edit it to meet their own needs.
#
# The commands in this file are executed each time a new csh shell
# is started.
#
# $Revision: 1.6 $
#

# list directories in columns
alias ls 'ls -C'

# Remember last 100 commands
set history = 100

# For interactive shells, set the prompt to show the host name and event number.
if ( $?prompt ) then
	if ( -o /bin/su ) then
		set prompt="`hostname -s` \!# "
	else
		set prompt="`hostname -s` \!% "
	endif
endif
alias emacs "emacs -nw"
alias emacs "emacs -nw"
alias emacs "emacs -nw"
alias e emacs
alias l less
alias lt ls -la
alias format "~nimrodav/lint/clang-format"
alias tidy clang-tidy 
