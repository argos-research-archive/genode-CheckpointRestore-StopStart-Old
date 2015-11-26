#include "session_component.h"

#include <launcher/child_process.h>

namespace LauncherManager {
  Session_component::Session_component()
  {
    _nextId = 0;
    launcher.init();
  }

  Session_component::~Session_component()
  {
  }

  int Session_component::create(String& filename, unsigned int ram_quota)
  {
    // ChildProcess* child = launcher.start_child(filename, ram_quota);
    // _children.insert(child);
    // child->setId(_nextId++);
    return 0;//child->getId();
  }

  void Session_component::kill(int process)
  {
    ChildProcess* child = _children.first();
    while(child != NULL)
    {
      if (child->getId() == process) {
        launcher.kill(child);
        _children.remove(child);
        child = NULL;
      } else {
        child = child->next();
      }
    }
  }

  void Session_component::pause(int process)
  {
    ChildProcess* child = _children.first();
    while(child != NULL)
    {
      if (child->getId() == process) {
        launcher.pause(child);
        child = NULL;
      } else {
        child = child->next();
      }
    }
  }

  void Session_component::resume(int process)
  {
    ChildProcess* child = _children.first();
    while(child != NULL)
    {
      if (child->getId() == process) {
        launcher.resume(child);
        child = NULL;
      } else {
        child = child->next();
      }
    }
  }

  void Session_component::say_hello()
  {
    PDBG("I am here... Hello.");
  }
}
