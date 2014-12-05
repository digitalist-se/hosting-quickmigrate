# Introduction
This is the frontend part of quick migrate, a tool for migrating sites more quickly by skipping some steps that are normally done by aegir.

# What does quick migrate do?
When Aegir executes a migrate, it normally does the following:

* Put the site into maintenance mode.
* Sync all resources back to the aegir hostmaster with rsync (for remote hosts)
* Make a database backup.
* Copy the data of the resources into the target to which we are migrating
* Create new configuration files that match the new location.
* Run updatedb
* Sync data back to the web fronts
* Remove the old site by removing on aegir and then sync.
* Put the new site out of maintenance mode.

This is fine for small installations, but for big installations with a lot of files, it takes a massive amount of time to sync the data over to the master.
Also, if you have a lot of sites, you need double the disk space. Another issue with this is if you have multiple web fronts. A common practice is to use
something like glusterFS for the file system, and then have the files directory be a symlink. Aegir breaks this, because it syncs the files over to the master
and then syncs it back as a normal folder.

Quick migrate does things a bit differently:

* Put the site in maintenance mode.
* Take a database dump.
* Remove the files folder completely from the aegir host.
* Move the files directory directly on the web host to another location using "mv".
* Sync the data (modules, themes, local.settings.php ...) to the aegir master.
* Move the site to the new platform on the hostmaster.
* Sync the site folder back to the web fronts.
* Move the files directory back to the new site folder
* Delete the old site folder on the web front(s).

The files directory is never backed up to the hostmaster, which saves a LOT of time when doing the migrate. There is a few things to note though:

* You **can't** move sites from different servers this way. If you need to do that, you need to use the normal migrate process.
* Files are not backed up. Use another means of backing data up!

# Installation
Put this module into your sites/all/modules folder of your hostmaster. You will also have to install the companion [provision plugin](http://github.com/nodeone/provision-quickmigrate).

