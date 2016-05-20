/*
 * Copyright 2016 RIFT.IO Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _KNI_NETLINK_H_
#define _KNI_NETLINK_H_

#ifndef KNI_NETLINK_PROTOCOL
#define KNI_NETLINK_PROTOCOL 31
#endif
extern int kni_net_id __read_mostly;

struct kni_net {
  unsigned long device_in_use; /* device in use flag */
  struct task_struct *kni_kthread;
  struct rw_semaphore kni_list_lock;
  struct list_head kni_list_head;
  struct sock *netlink_sock;
};

enum kni_netlink_msg_types {
   KNI_NETLINK_MSG_BASE = NLMSG_MIN_TYPE,
   KNI_NETLINK_MSG_TX = KNI_NETLINK_MSG_BASE,
   KNI_NETLINK_MSG_MAX
};

enum kni_netlink_attr {
  KNI_NETLINK_UNSPEC,
  KNI_NETLINK_METADATA,
  KNI_NETLINK_DATA,
  __KNI_NETLINK_MAX,
};

#define KNI_NETLINK_MAX (__KNI_NETLINK_MAX - 1)

#define KNI_NETLINK_GRP 1
int 
kni_netlink_net_init(struct net *net);
void kni_netlink_net_exit(struct net *net);
int
kni_nl_unicast(int pid, struct sk_buff *skb,
               struct net_device *dev);

#endif

