<!--startmeta
custom_edit_url: "https://github.com/netdata/netdata/edit/master/integrations/cloud-notifications/integrations/mattermost.md"
meta_yaml: "https://github.com/netdata/netdata/edit/master/integrations/cloud-notifications/metadata.yaml"
sidebar_label: "Mattermost"
learn_status: "Published"
learn_rel_path: "Alerts & Notifications/Notifications/Centralized Cloud Notifications"
message: "DO NOT EDIT THIS FILE DIRECTLY, IT IS GENERATED BY THE NOTIFICATION'S metadata.yaml FILE"
endmeta-->

# Mattermost


<img src="https://netdata.cloud/img/mattermost.png" width="150"/>


From the Netdata Cloud UI, you can manage your space's notification settings and enable the configuration to deliver notifications on Mattermost.


<img src="https://img.shields.io/badge/maintained%20by-Netdata-%2300ab44" />

## Setup

### Prerequisites

- A Netdata Cloud account
- Access to the Netdata Space as an **Admin**
- The Netdata Space needs to be on a paid plan
- You need to have permissions on Mattermost to add new integrations.
- You need to have a Mattermost app on your workspace to receive the webhooks.

### Mattermost Server Configuration

Steps to configure your Mattermost to receive notifications from Netdata:

1. In Mattermost, go to Product menu > Integrations > Incoming Webhook
  - If you don’t have the Integrations option, incoming webhooks may not be enabled on your Mattermost server or may be disabled for non-admins. They can be enabled by a System Admin from System Console > Integrations > Integration Management. Once incoming webhooks are enabled, continue with the steps below.
2. Select Add Incoming Webhook and add a name and description for the webhook. The description can be up to 500 characters
3. Select the channel to receive webhook payloads, then select Add to create the webhook
4. You will end up with a webhook endpoint that looks like below:
  `https://your-mattermost-server.com/hooks/xxx-generatedkey-xxx`

  - Treat this endpoint as a secret. Anyone who has it will be able to post messages to your Mattermost instance.

For more details please check Mattermost's article [Incoming webhooks for Mattermost](https://developers.mattermost.com/integrate/webhooks/incoming/).

### Netdata Configuration Steps

1. Click on the **Space settings** cog (located above your profile icon)
2. Click on the **Notification** tab
3. Click on the **+ Add configuration** button (near the top-right corner of your screen)
4. On the **Mattermost** card click on **+ Add**
5. A modal will be presented to you to enter the required details to enable the configuration:
  * **Notification settings** are Netdata specific settings
    - Configuration name - you can optionally provide a name for your configuration you can easily refer to it
    - Rooms - by specifying a list of Rooms you are select to which nodes or areas of your infrastructure you want to be notified using this configuration
    - Notification - you specify which notifications you want to be notified using this configuration: All Alerts and unreachable, All Alerts, Critical only
  * **Integration configuration** are the specific notification integration required settings, which vary by notification method. For Mattermost:
    - Webhook URL - URL provided on Mattermost for the channel you want to receive your notifications

