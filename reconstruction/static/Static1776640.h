// Source exposure: binary-analysis; no external implementation source reused.
// Static1776640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776640*);
    virtual void release(Static1776640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776640*);
struct Static1776640 {
    void* value;
    Static1776640();
    ~Static1776640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
