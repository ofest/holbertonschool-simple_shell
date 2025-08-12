void n_interactive(int argc, char **argv)
{
    execvp(argv[0], argv);
    perror("Error executing command"); // Only executes if execvp fails
    return (-1); // Or an appropriate exit stat 
}