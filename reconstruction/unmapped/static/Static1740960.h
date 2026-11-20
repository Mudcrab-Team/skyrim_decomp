// Source exposure: binary-analysis; no external implementation source reused.
// Static1740960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740960*);
    virtual void release(Static1740960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740960*);
struct Static1740960 {
    void* value;
    Static1740960();
    ~Static1740960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
