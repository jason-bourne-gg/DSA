 Handle invalid slot
    try
    {
        system.handleInvalidSlot(9);
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << endl;
    }