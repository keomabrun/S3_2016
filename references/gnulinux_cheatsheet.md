# The PW GNU/Linux Cheat-Sheet

### File Operations

touch myfile        => create a file
rm myfile           => remove a file
mv myfile1 myfile2  => move/rename a file
nano myfile         => edit a file content (without graphical interface)
gedit myfile        => edit a file content (with graphical interface)

note: adding a "&" symbol starts the program in a different process

### File Permission

sudo chown owner:group myfile   => change file owner
sudo chmod XXX myfile           => change file permissions
    where X corresponds to 3 bits for Owner Group Others, representing rwx permissions

note: directories need to have execution permission to be openned

### Directories Operations

mkdir mydirectory
rm -r mydirectory (recursive remove)

### Package/Program Operations

sudo apt-get install mypackage

### Git Operations

git add myfile  => add the file to the next commit
git mv myfile   => move/rename the file in git
git rm myfile   => remove the file in git

git commit myfile -m "my message"   => pack the modifications and comment them

git push origin master  => push the lastests commits to the master branch of the origin server
git pull origin master  => pull the lastests commits from the master branch of the origin server
