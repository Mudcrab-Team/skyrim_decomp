// Source exposure: binary-analysis; no external implementation source reused.
// Static1763090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763090*);
    virtual void release(Static1763090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763090*);
struct Static1763090 {
    void* value;
    Static1763090();
    ~Static1763090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
