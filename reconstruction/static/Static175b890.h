// Source exposure: binary-analysis; no external implementation source reused.
// Static175b890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b890*);
    virtual void release(Static175b890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b890*);
struct Static175b890 {
    void* value;
    Static175b890();
    ~Static175b890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
